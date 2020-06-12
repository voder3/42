/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 23:55:20 by artderva          #+#    #+#             */
/*   Updated: 2020/06/12 15:43:44 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cd_oldpwd(t_msh *data)
{
	char	**str;
	char	*oldpwd;
	int		ret;

	oldpwd = ft_getenv(data->env_var, "OLDPWD");
	if (!oldpwd || !*oldpwd)
		return (ft_error(NULL, "cd: OLDPWD not set"));
	if (!(str = (char**)malloc(sizeof(char*) * 2)))
		return (ft_error(NULL, "memory allocation failed"));
	str[0] = oldpwd;
	str[1] = NULL;
	ret = ft_cd(str, data);
	free(str);
	return (ret);
}

int		ft_cd(char **str, t_msh *data)
{
	char	opt;
	char	*opr;
	char	*curpath;
	int		i;

	i = 0;
	if (!(opt = cd_getopt(str, &i)))
		return (0);
	opr = str[i];
	if (!opr)
		return (cd_home(data));
	else if (!ft_strcmp(opr, "-"))
		return (cd_oldpwd(data));
	if (!(curpath = cd_setcurpath(data, opr)))
		return (0);
	if (opt == 'L')
		return (cd_logically(data, curpath, opr));
	return (cd_change_directory(data, curpath, opr, NULL));
}

int		ft_call_cd(t_msh *msh)
{
	return (ft_cd(msh->input + 1, msh));
}
