/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:12:49 by artderva          #+#    #+#             */
/*   Updated: 2018/11/18 20:01:37 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size)
	{
		while (dst[i])
			i++;
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (size >= dlen)
		return (dlen + slen);
	return (slen + size);
}
