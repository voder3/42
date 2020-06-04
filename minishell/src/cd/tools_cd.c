/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmerieux <hmerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:54:53 by hmerieux          #+#    #+#             */
/*   Updated: 2020/06/04 20:06:50 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <dirent.h>

char		*ft_pathjoin(char *str1, char *str2)
{
	char	*ret;
	char	*tmp;
	size_t	s1len;

	if (!str1 || !str2)
		return (0);
	s1len = ft_strlen(str1);
	if (!s1len || (str1[s1len - 1] == '/'))
		return (ft_strjoin(str1, str2));
	if (!(tmp = ft_strjoin(str1, "/")))
		return (0);
	ret = ft_strjoin(tmp, str2);
	free(tmp);
	return (ret);
}

char		*ft_strrep(char *str, char *rem, char *rep)
{
	char	*ret;
	char	*occurence;
	size_t	replen;

	replen = rep ? ft_strlen(rep) : 0;
	if (!str || !rem)
		return (0);
	if (!(occurence = ft_strstr(str, rem)))
		return (str);
	if (!(ret = ft_strnew(ft_strlen(str) - ft_strlen(rem) + replen)))
		return (0);
	ft_strncpy(ret, str, occurence - str);
	if (replen)
		ft_strcat(ret, rep);
	ft_strcat(ret, occurence + ft_strlen(rem));
	return (ret);
}
/*
int			ft_isdir(char *path)
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
}*/


int		cd_update_pwd(t_msh *data, char *pwd, char *oldpwd)
{
	data->input = (char **)malloc(sizeof(char *) * 5);
	data->input[1] = ft_strdup("PWD");
	data->input[2] = ft_strdup(pwd);
	data->input[3] = ft_strdup("1");
	data->input[4] = NULL;
	if (ft_setenv(data))
		return (0);
	data->input[1] = ft_strdup("OLDPWD");
	data->input[2] = ft_strdup(oldpwd);
	data->input[3] = ft_strdup("1");
	data->input[4] = NULL;
	if (ft_setenv(data))
		return (0);
	return (1);
}
