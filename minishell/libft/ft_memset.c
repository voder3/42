/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:57:11 by artderva          #+#    #+#             */
/*   Updated: 2018/11/20 15:35:05 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*b1;

	b1 = (char *)b;
	i = 0;
	while (i < len)
	{
		b1[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
