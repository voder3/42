/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:24:59 by artderva          #+#    #+#             */
/*   Updated: 2020/06/05 18:25:03 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>
#include <sys/stat.h>

int			check_enoent(char *path)
{
	DIR				*dir;
	struct dirent	*dit;
	int				ret;
	char			*tmp;

	ret = 0;
	if (!*path)
		return (1);
	if (!(tmp = ft_strrchr(path, '/')))
		return (0);
	*tmp = '\0';
	if (tmp == path)
		dir = opendir("/");
	else
		dir = opendir(path);
	*tmp = '/';
	if (!dir)
		return (1);
	while (!ret && (dit = readdir(dir)))
		if (!ft_strcmp(dit->d_name, tmp + 1))
			ret = 1;
	closedir(dir);
	return (ret);
}

int			check_eacces(char *path)
{
	struct stat		buf;

	if (!*path)
	{
		if (!lstat("/", &buf))
			if (!(buf.st_mode & S_IXUSR))
				return (0);
	}
	else
	{
		if (!lstat(path, &buf))
			if (!(buf.st_mode & S_IXUSR))
				return (0);
	}
	return (1);
}

int			check_enotdir(char *path)
{
	struct stat		buf;

	if (!lstat(path, &buf))
		if (!(S_IFDIR == (S_IFMT & buf.st_mode)))
			return (0);
	return (1);
}

int			check_eloop(char *path)
{
	struct stat		buf;

	if (stat(path, &buf) < 0)
		if (!lstat(path, &buf) && S_IFLNK == (S_IFMT & buf.st_mode))
			return (0);
	return (1);
}

int			check_whole_path(char *path)
{
	char			*idx;
	char			tmp;

	idx = path;
	while (1)
	{
		if ((idx = ft_strchr(idx, '/')))
		{
			tmp = *idx;
			*idx = '\0';
		}
		if (!check_enoent(path))
			return (1);
		if (!check_eloop(path))
			return (2);
		if (!check_enotdir(path))
			return (3);
		if (!check_eacces(path))
			return (4);
		if (!idx)
			return (0);
		*(idx) = tmp;
		idx++;
	}
}
