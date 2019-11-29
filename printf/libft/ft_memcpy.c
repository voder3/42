/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:06:14 by artderva          #+#    #+#             */
/*   Updated: 2018/11/20 15:30:19 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d1;
	char	*s1;

	d1 = (char *)dst;
	s1 = (char *)src;
	i = 0;
	while (i < n)
	{
		d1[i] = s1[i];
		i++;
	}
	return (dst);
}
