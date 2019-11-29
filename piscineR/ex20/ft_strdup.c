/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:53:26 by artderva          #+#    #+#             */
/*   Updated: 2018/11/07 15:11:25 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dup;

	len = 0;
	i = -1;
	while (src[++i])
		len++;
	if (!(dup = malloc(sizeof(char) * len + 1)))
		return (0);
	i = -1;
	while (src[++i])
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}
