/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclnjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:20 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:20 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strclnjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (!(ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	if (!(ret = ft_strcat(ret, s1))
	|| !(ret = ft_strcat(ret, s2)))
		return (NULL);
	if (s1)
		ft_strdel((char**)&s1);
	if (s2)
		ft_strdel((char**)&s2);
	return (ret);
}
