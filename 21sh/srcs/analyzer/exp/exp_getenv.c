/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_getenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:12 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:12 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyzer.h"
#include "sh.h"
#include "libft.h"
#include "var.h"

char	*exp_getenv(char *str, int type, int hash)
{
	char	*res;

	res = NULL;
	if (type && !hash)
		return (find_var_value(cfg_shell()->sp, str));
	if (type && hash)
		return (find_var_value(cfg_shell()->sp, str + 1));
	if (!type && !hash)
	{
		if (!(res = find_var_value(cfg_shell()->env, str)))
			res = find_var_value(cfg_shell()->intern, str);
	}
	else if (!type && hash)
	{
		if (!(res = find_var_value(cfg_shell()->env, str + 1)))
			res = find_var_value(cfg_shell()->intern, str + 1);
	}
	return (res);
}
