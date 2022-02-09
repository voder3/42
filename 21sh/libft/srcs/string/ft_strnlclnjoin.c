/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlclnjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:22 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:22 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnlclnjoin(char const *s1, char const *s2, size_t n)
{
	char	*ret;

	if (!(ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	if (!(ret = ft_strcat(ret, s1))
	|| !(ret = ft_strncat(ret, s2, n)))
		return (NULL);
	if (s1)
		ft_strdel((char**)&s1);
	return (ret);
}
