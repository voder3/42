/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:22:51 by artderva          #+#    #+#             */
/*   Updated: 2020/06/12 16:58:40 by artderva         ###   ########.fr       */
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
	if (!(ret = ft_strjoin1(tmp, str2)))
		ft_ex(NULL, "memory allocation failed");
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

int		cd_update_oldpwd(t_msh *data, char *oldpwd)
{
	ft_del_tab((void **)data->input);
	if (!(data->input = (char **)malloc(sizeof(char *) * 5)))
		ft_ex(NULL, "memory allocation failed");
	if (!(data->input[0] = ft_strdup("setenv")))
		ft_ex(NULL, "memory allocation failed");
	if (!(data->input[1] = ft_strdup("OLDPWD")))
		ft_ex(NULL, "memory allocation failed");
	if (!(data->input[2] = ft_strdup(oldpwd)))
		ft_ex(NULL, "memory allocation failed");
	if (!(data->input[3] = ft_strdup("1")))
		ft_ex(NULL, "memory allocation failed");
	data->input[4] = NULL;
	ft_setenv(data);
	return (1);
}

int		cd_update_pwd(t_msh *data, char *pwd, char *oldpwd)
{
	ft_del_tab((void **)data->input);
	if (!(data->input = (char **)malloc(sizeof(char *) * 5)))
		ft_ex(NULL, "memory allocation failed");
	if (!(data->input[0] = ft_strdup("setenv")))
		ft_ex(NULL, "memory allocation failed");
	if (!(data->input[1] = ft_strdup("PWD")))
		ft_ex(NULL, "memory allocation failed");
	if (!(data->input[2] = ft_strdup(pwd)))
		ft_ex(NULL, "memory allocation failed");
	if (!(data->input[3] = ft_strdup("1")))
		ft_ex(NULL, "memory allocation failed");
	data->input[4] = NULL;
	ft_setenv(data);
	return (cd_update_oldpwd(data, oldpwd));
}
