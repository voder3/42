/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:30:27 by artderva          #+#    #+#             */
/*   Updated: 2018/11/20 17:15:59 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tr;

	if (!s)
		return (NULL);
	if (!(tr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		tr[i] = s[start];
		i++;
		start++;
	}
	tr[i] = '\0';
	return (tr);
}
