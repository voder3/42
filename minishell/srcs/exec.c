/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:31:47 by artderva          #+#    #+#             */
/*   Updated: 2020/06/15 20:50:00 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "dirent.h"
#include <sys/wait.h>

static char	*which_path(char *path, char *exec, char **tab, int i)
{
	char	*dst;

	if (!(path = ft_strdup(tab[i])))
		ft_ex(NULL, "memory allocation failed");
	ft_del_tab((void **)tab);
	if (!(dst = ft_strjoin1(path, "/")))
		ft_ex(NULL, "memory allocation failed");
	if (!(dst = ft_strjoin1(dst, exec)))
		ft_ex(NULL, "memory allocation failed");
	return (dst);
}

char		*absolute_path(char *exec)
{
	char	*ret;

	if (ft_isdir(exec))
		ft_error(exec, ": Is a directory");
	else if (is_file(exec, ft_strrchr(exec, '/')))
	{
		if (!(ret = ft_strdup(exec)))
			ft_ex(NULL, "memory allocation failed");
		return (ret);
	}
	else
		ft_error(exec, ": No such file or directory");
	return (NULL);
}

char		**ft_err_which(char *path, char *exec)
{
	char	**tab;

	if (!path)
	{
		ft_error(exec, ": command not found");
		return (NULL);
	}
	if (!(tab = ft_strsplit(path, ':')))
		ft_ex(NULL, "memory allocation failed");
	return (tab);
}

char		*ft_which(char *path, char *exec)
{
	struct dirent	*file;
	char			**tab;
	DIR				*dir;
	int				i;

	i = -1;
	if (ft_strchr(exec, '/'))
		return (absolute_path(exec));
	if (!(tab = ft_err_which(path, exec)))
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
			return (which_path(path, exec, tab, i));
	}
	ft_error(exec, ": command not found");
	ft_del_tab((void **)tab);
	return (NULL);
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
				return (ft_err_fork());
		if (pid == -1)
			ft_ex(NULL, "fork failed");
		else
			wait(&status);
		ft_strdel(&exec);
	}
	ft_del_tab((void **)env);
	return (0);
}
