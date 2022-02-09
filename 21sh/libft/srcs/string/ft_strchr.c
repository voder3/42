/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:20 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:20 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (str && *str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
