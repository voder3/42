/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmerieux <hmerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:45:58 by hmerieux          #+#    #+#             */
/*   Updated: 2020/01/22 17:58:09 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/ft_printf.h"

char			cd_getopt(char **str, int *i)
{
	char	opt;
	int		a;

	opt = 'L';
	a = *i;
	while (str[a] && str[a][0] == '-' && str[a][1])
	{
		if (str[a][1] == 'P' || str[a][1] == 'L')
			opt = str[a][1];
		else if (str[a][1] != '-' || (str[a][1] == '-' && str[a][2]))
		{
			ft_printf("minishell: cd: -%c: invalid option\n",
			str[a][1]);
			ft_printf("cd: usage: cd [-L|-P] [dir]\n");
			return (0);
		}
		if (str[a][1] == '-')
			break ;
		a++;
	}
	*i = a;
	return (opt);
}

static char		*ft_del_dots(char *curpath)
{
	char	*res;
	size_t	clen;

	if (!curpath)
		return (0);
	clen = ft_strlen(curpath);
	if (ft_strnstr(curpath, "./", 2))
		res = ft_strdup(curpath + 2);
	else if (clen >= 2 && curpath[clen - 1] == '.' && curpath[clen - 2] == '/')
	{
		curpath[clen - 2] = '\0';
		res = ft_strdup(curpath);
	}
	else if (ft_strstr(curpath, "/./"))
		res = ft_strrep(curpath, "/./", "/");
	else
		return (curpath);
	free(curpath);
	return (ft_del_dots(res));
}

static char		*ft_del_dotdots2(char *curpath, int i)
{
	char	*res;
	char	*tmp;
	char	*tmp2;
	size_t	res_len;

	if (!ft_strncmp(curpath, "/..", 3))
		return (ft_strrep(curpath, "..", NULL));
	if (!(tmp = ft_strdup(curpath)))
		return (0);
	tmp[i - 1] = '\0';
	tmp2 = ft_strrchr(tmp, '/') + 1;
	tmp[i - 1] = '/';
	if (tmp[i + 2])
		tmp[i + 3] = '\0';
	res = ft_strrep(curpath, tmp2, NULL);
	res_len = ft_strlen(res);
	if (res_len > 1 && res[res_len - 1] == '/')
		res[res_len - 1] = '\0';
	free(tmp);
	return (res);
}

static char		*ft_del_dotdots(char *curpath, char *opr)
{
	int		i;
	char	*res;

	i = -1;
	res = NULL;
	if (!curpath)
		return (0);
	while (curpath[++i])
	{
		if (curpath[i] == '.' && curpath[i + 1] == '.' && i >= 1
		&& curpath[i - 1] == '/' && (!curpath[i + 2] || curpath[i + 2] == '/')
		&& !((i == 3 || (i > 3 && curpath[i - 4] == '/'))
		&& curpath[i - 3] == '.' && curpath[i - 2] == '.'))
		{
			res = ft_del_dotdots2(curpath, i);
			free(curpath);
			return (ft_del_dotdots(res, opr));
		}
	}
	return (curpath);
}

char			*cd_del_dotcomponents(char *curpath, char *opr)
{
	if (!(curpath = ft_del_dots(curpath)))
		return (0);
	if (!(curpath = ft_del_dotdots(curpath, opr)))
		return (0);
	return (curpath);
}