/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmerieux <hmerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:51:38 by hmerieux          #+#    #+#             */
/*   Updated: 2020/03/02 17:38:11 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/ft_printf.h"

int		cd_oldpwd(t_msh *data)
{
	char	**str;
	char	*oldpwd;
	int		ret;

	oldpwd = ft_getenv(data->env_var, "OLDPWD");
	if (!oldpwd || !*oldpwd)
	{
		ft_printf("minishell: cd: OLDPWD not set\n");
		return (-1);
	}
	if (!(str = (char**)malloc(sizeof(char*) * 2)))
		return (0);
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
		return (-1);
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
