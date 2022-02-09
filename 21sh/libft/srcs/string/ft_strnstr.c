/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:22 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:22 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	unsigned long		i;
	unsigned int		r;
	unsigned int		j;

	i = 0;
	if (n[0] == '\0')
		return ((char *)h);
	while (h[i] && i < len)
	{
		j = 0;
		if (h[i] == n[j])
		{
			r = i;
			while (h[i + j] == n[j] && h[i + j] && n[j]
					&& (i + j) < len)
				j++;
			if (n[j] == '\0')
				return ((char *)&h[r]);
		}
		i++;
	}
	return (NULL);
}
