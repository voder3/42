/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmerieux <hmerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:15:46 by hmerieux          #+#    #+#             */
/*   Updated: 2020/01/13 16:42:21 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "dirent.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

static char		*which_path(char *path, char *exec)
{
	char	*dst;

	dst = ft_strnew(ft_strlen(path) + ft_strlen(exec) + 1);
	ft_strcat(dst, path);
	ft_strcat(dst, "/");
	ft_strcat(dst, exec);
	return (dst);
}

char			*ft_which(char *paths, char *exec)
{
	struct dirent	*file;
	char			**tab;
	DIR				*dir;
	int				i;

	i = -1;
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
			return (which_path(tab[i], exec));
	}
	return (NULL);
}

int			ft_is_exec(char *str, t_msh *msh)
{
	char	*exec;
	pid_t	pid;
	int		status;

	if ((exec = ft_which(msh->path, msh->input[0])) == NULL)
	{
		ft_putstr("msh : ");
		ft_putstr(str);
		ft_putendl(": command not found");
//		printf("msh: %s: command not found", str);
		return (0);
	}
	else
	{
		pid = fork();
		if (pid == 0)
			if (execve(exec, msh->input, msh->envp) == -1)
				return (0);
		if (pid == -1)
			perror("fork");
		else
			wait(&status);
	}
	return (1);

}
