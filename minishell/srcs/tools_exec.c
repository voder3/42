/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:31:47 by artderva          #+#    #+#             */
/*   Updated: 2020/06/15 20:49:39 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "dirent.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int		ft_isdir(char *path)
{
	DIR		*dir;

	if (!path)
		return (0);
	if ((dir = opendir(path)))
	{
		closedir(dir);
		return (1);
	}
	return (0);
}

int		is_file(char *path, char *str)
{
	DIR				*dir;
	struct dirent	*dit;
	int				ret;
	char			*name;

	ret = 0;
	if (!*str)
		return (0);
	if (*str == '/')
		*str = '\0';
	name = *str ? str : str + 1;
	if (!(dir = opendir(path)))
	{
		*str = *str ? *str : '/';
		return (0);
	}
	while (!ret && (dit = readdir(dir)))
		if (!ft_strcmp(dit->d_name, name))
			ret = 1;
	closedir(dir);
	*str = *str ? *str : '/';
	return (ret);
}

char		**env_to_tab(t_list *env)
{
	char		**ar;
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (!(ar = (char **)malloc(sizeof(char *) * (i + 1))))
		ft_ex(NULL, "memory allocation failed");
	i = 0;
	while (env)
	{
		if (!(ar[i] = ft_strjoin(((t_var *)(env->content))->tab[0], "=")))
			ft_ex(NULL, "memory allocation failed");
		if (!(ar[i] = ft_strjoin1(ar[i], ((t_var *)(env->content))->tab[1])))
			ft_ex(NULL, "memory allocation failed");
		env = env->next;
		i++;
	}
	ar[i] = NULL;
	return (ar);
}
