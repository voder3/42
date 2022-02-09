/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strselect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:22 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:22 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenselect(char *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str != c)
			i++;
		str++;
	}
	return (i);
}

static void		ft_cpyselect(char *src, char *dst, char c)
{
	while (*src)
	{
		if (*src == c)
			src++;
		else
		{
			*dst = *src;
			dst++;
			src++;
		}
	}
}

char			*ft_strselect(char *str, char c)
{
	char	*dst;
	int		len;

	len = ft_lenselect(str, c);
	dst = ft_strnew(len);
	if (!dst)
		return (NULL);
	ft_cpyselect(str, dst, c);
	return (dst);
}
