/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 19:34:35 by artderva          #+#    #+#             */
/*   Updated: 2020/06/12 17:01:40 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cd_home(t_msh *data)
{
	char	**str;
	char	*home;
	int		ret;

	home = ft_getenv(data->env_var, "HOME");
	if (!home)
		return (ft_error(NULL, "cd: HOME not set"));
	if (!(str = (char**)malloc(sizeof(char*) * 2)))
		ft_ex(NULL, "memory allocation failed");
	str[0] = home;
	str[1] = NULL;
	ret = ft_cd(str, data);
	free(str);
	return (ret);
}

char	*cd_setcurpath(t_msh *data, char *opr)
{
	char	*ret;
	char	**cdpath;

	if (*opr != '/' && (ft_strncmp(opr, "./", 2) || ft_strcmp(opr, "."))
			&& ((ft_strncmp(opr, "../", 3)) || ft_strcmp(opr, "..")))
		return (ft_strdup(opr));
	ret = ft_getenv(data->env_var, "CDPATH");
	cdpath = ft_strsplit(ret, ':');
	while (cdpath && *cdpath)
	{
		ret = ft_pathjoin(*cdpath, opr);
		if (ft_isdir(ret))
			break ;
		ft_strdel(&ret);
		cdpath++;
	}
	ft_del_tab((void **)cdpath);
	if (!ret && (ft_isdir(opr)))
		return (ft_strdup(opr));
	return (ret);
}

int		cd_set_relativepath(t_msh *data, char *curpath, char *opr, char *pwd)
{
	char	*tmp;
	char	*oldpath;
	int		ret;

	oldpath = ft_strdup(curpath);
	if (ft_strlen(curpath) >= PATH_MAX && ft_strlen(opr) < PATH_MAX
	&& !ft_strncmp(curpath, pwd, ft_strlen(pwd)))
	{
		tmp = curpath[ft_strlen(pwd)] == '/' ?
		ft_strdup(curpath + ft_strlen(pwd) + 1) :
		ft_strdup(curpath + ft_strlen(pwd));
		curpath = tmp;
	}
	free(pwd);
	ret = cd_change_directory(data, curpath, opr, oldpath);
	free(oldpath);
	return (ret);
}

int		cd_logically(t_msh *data, char *curpath, char *opr)
{
	char	*tmp;
	char	*pwd;

	if (!(pwd = ft_strdup(ft_getenv(data->env_var, "PWD"))))
		if (!(pwd = getcwd(NULL, 0)))
			ft_ex(NULL, "memory allocation failed");
	if (*curpath != '/')
	{
		tmp = curpath;
		if (!(curpath = ft_pathjoin(pwd, curpath)))
			ft_ex(NULL, "memory allocation failed");
		free(tmp);
	}
	if (!(curpath = cd_del_dotcomponents(curpath, opr)))
		ft_ex(NULL, "memory allocation failed");
	return (cd_set_relativepath(data, curpath, opr, pwd));
}

int		cd_change_directory(t_msh *data, char *curpath, char *opr, char *pwd)
{
	char	*oldpwd;
	char	*error;

	if (!(oldpwd = ft_strdup(ft_getenv(data->env_var, "PWD"))))
		if (!(oldpwd = getcwd(NULL, 0)))
			ft_ex(NULL, "memory allocation failed");
	if (chdir(curpath) == -1)
	{
		check_chdir_errors(&error, curpath, opr);
		ft_strdel(&curpath);
		ft_strdel(&oldpwd);
		return (display_cd_errors(error));
	}
	free(curpath);
	if (!pwd && !(pwd = getcwd(NULL, 0)))
		ft_ex(NULL, "memory allocation failed");
	if (!cd_update_pwd(data, pwd, oldpwd))
		ft_ex(NULL, "memory allocation failed");
	free(oldpwd);
	return (1);
}
