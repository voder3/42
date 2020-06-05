/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 23:55:50 by artderva          #+#    #+#             */
/*   Updated: 2020/06/05 00:00:16 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			display_cd_errors(char *error)
{
	if (!(error))
		return (0);
	ft_error("cd :", error);
	free(error);
	return (1);
}

int			check_enametoolong(char *path)
{
	int		i;
	char	*buf;

	i = 2;
	if (ft_strlen(path) >= PATH_MAX)
		return (0);
	while ((buf = ft_strcut(path, "/", i)))
	{
		if (ft_strlen(buf) >= NAME_MAX)
		{
			free(buf);
			return (0);
		}
		if (!*buf)
		{
			free(buf);
			break ;
		}
		free(buf);
		i++;
	}
	return (1);
}

int			check_chdir_errors(char **error, char *path, char *opr)
{
	int ret;

	if (!check_enametoolong(path))
	{
		*error = (ft_strjoin(opr, ": File name too long\n"));
		return (1);
	}
	ret = check_whole_path(path);
	if (ret == 1)
		*error = (ft_strjoin(opr, ": No such file or directory\n"));
	if (ret == 2)
		*error = (ft_strjoin(opr, ": Symbolic links error\n"));
	if (ret == 3)
		*error = (ft_strjoin(opr, ": Not a directory\n"));
	if (ret == 4)
		*error = (ft_strjoin(opr, ": Permission denied\n"));
	if (!ret)
		return (0);
	return (1);
}
