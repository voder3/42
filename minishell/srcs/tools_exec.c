/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:31:47 by artderva          #+#    #+#             */
/*   Updated: 2020/06/12 15:30:50 by artderva         ###   ########.fr       */
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
	DIR		*dir;
	struct dirent	*dit;
	int		ret;
	char		*name;

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
