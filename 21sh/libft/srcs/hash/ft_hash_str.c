/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:17 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:17 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_hash_str(t_hash_map *map, char *key)
{
	uint32_t	res;
	int			i;
	int			len;

	res = 0;
	i = 0;
	if (!map)
		return (0);
	len = ft_strlen(key);
	while (i < len)
		res += res * 11 + key[i++];
	if (map->size == 1)
		return (1);
	res %= (map->size - 1);
	return (res);
}
