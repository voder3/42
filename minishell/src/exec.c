/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:31:47 by artderva          #+#    #+#             */
/*   Updated: 2020/06/06 18:33:04 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "dirent.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

static char	*which_path(char *path, char *exec)
{
	char	*dst;

	if (!(dst = ft_strnew(ft_strlen(path) + ft_strlen(exec) + 1)))
		ft_ex(NULL, "memory allocation failed");
	ft_strcat(dst, path);
	ft_strcat(dst, "/");
	ft_strcat(dst, exec);
	ft_strdel(&path);
	return (dst);
}

char		*absolute_path(char *exec)
{
	if (ft_isdir(exec))
		ft_error(exec, ": Is a directory");
	else if (is_file(exec, ft_strrchr(exec, '/')))
		return (exec);
	else
		ft_error(exec, ": No such file or directory");
	return (NULL);
}

char		*ft_which(char *paths, char *exec)
{
	struct dirent	*file;
	char		**tab;
	DIR		*dir;
	int			i;

	i = -1;
	if (ft_strchr(exec, '/'))
		return (absolute_path(exec));
	if (!(paths && exec && (tab = ft_strsplit(paths, ':'))))
		return (NULL);
	while (tab[++i])
	{
		if (!(dir = opendir(tab[i])))
			continue;
		while ((file = readdir(dir)))
			if (ft_strcmp(file->d_name, exec) == 0)
				break ;
		closedir(dir);
		if (file)
		{	
			paths = ft_strdup(tab[i]);
			ft_del_tab((void **)tab);
			return (which_path(paths, exec));
		}
	}
	ft_error(exec, ": command not found");
	ft_del_tab((void **)tab);
	return (NULL);
}

char		**env_to_tab(t_list *env)
{
	char		**arr;
	t_list		*cpy;
	int			i;

	i = 0;
	cpy = env;
	while (cpy)
	{
		i++;
		cpy = cpy->next;
	}
	if (!(arr = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (env)
	{
		arr[i] = ft_strjoin(((t_var*)(env->content))->tab[0], "=");
		arr[i] = ft_strjoin1(arr[i], ((t_var*)(env->content))->tab[1]);
		env = env->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int			ft_is_exec(t_msh *msh)
{
	char		*exec;
	pid_t		pid;
	int			status;
	char		*path;
	char		**env;

	path = ft_getenv(msh->env_var, "PATH");
	if ((exec = ft_which(path, msh->input[0])) == NULL)
		return (0);
	else
	{
		env = env_to_tab(msh->env_var);
		pid = fork();
		if (pid == 0)
			if (execve(exec, msh->input, env) == -1)
				return (ft_error(NULL, "execution failed"));
		if (pid == -1)
			ft_ex(NULL, "fork failed");
		else
			wait(&status);
	}
	ft_strdel(&exec);
	ft_del_tab((void **)env);
	return (0);
}
