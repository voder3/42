/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:07:52 by artderva          #+#    #+#             */
/*   Updated: 2020/06/12 15:45:49 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strcut(char *str, char *delim, unsigned int field)
{
	int		i;
	char	*res;
	char	*tmp;

	if (!str || !delim)
	{
		return (0);
	}
	if ((tmp = ft_strstr(str, delim)) && field > 1)
		return (ft_strcut(tmp + ft_strlen(delim), delim, field - 1));
	else if (field == 0 || field > 1)
		return (ft_strnew(0));
	if (tmp)
	{
		i = tmp - str;
		if (!(res = ft_strnew(i)))
			return (0);
		ft_strncpy(res, str, i);
	}
	else
		res = ft_strdup(str);
	return (res);
}
