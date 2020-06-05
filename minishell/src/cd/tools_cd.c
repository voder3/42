/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:22:51 by artderva          #+#    #+#             */
/*   Updated: 2020/06/05 18:26:10 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <dirent.h>

char	*ft_pathjoin(char *str1, char *str2)
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
		ft_ex(NULL, "memory allocation failed");
	ret = ft_strjoin(tmp, str2);
	free(tmp);
	return (ret);
}

char	*ft_strrep(char *str, char *rem, char *rep)
{
	char	*ret;
	char	*occurence;
	size_t	replen;

	replen = rep ? ft_strlen(rep) : 0;
	if (!str || !rem)
		ft_ex(NULL, "memory allocation failed");
	if (!(occurence = ft_strstr(str, rem)))
		return (str);
	if (!(ret = ft_strnew(ft_strlen(str) - ft_strlen(rem) + replen)))
		ft_ex(NULL, "memory allocation failed");
	ft_strncpy(ret, str, occurence - str);
	if (replen)
		ft_strcat(ret, rep);
	ft_strcat(ret, occurence + ft_strlen(rem));
	return (ret);
}

int		cd_update_pwd(t_msh *data, char *pwd, char *oldpwd)
{
	data->input = (char **)malloc(sizeof(char *) * 5);
	data->input[1] = ft_strdup("PWD");
	data->input[2] = ft_strdup(pwd);
	data->input[3] = ft_strdup("1");
	data->input[4] = NULL;
	ft_setenv(data);
	data->input[1] = ft_strdup("OLDPWD");
	data->input[2] = ft_strdup(oldpwd);
	data->input[3] = ft_strdup("1");
	data->input[4] = NULL;
	ft_setenv(data);
	return (1);
}
