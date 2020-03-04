/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:21:15 by artderva          #+#    #+#             */
/*   Updated: 2018/11/20 17:32:12 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str1;

	str1 = (char *)s1;
	i = 0;
	if (!s2[0])
		return (str1);
	while (s1[i])
	{
		j = 0;
		while (s2[j] == s1[i + j])
		{
			if (!(s2[j + 1]) && i + j < len)
				return (str1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
