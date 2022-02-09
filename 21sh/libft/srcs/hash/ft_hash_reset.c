/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:17 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:17 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hash_reset(t_hash_map **map, void (*del)(void *data), uint32_t size)
{
	ft_hash_del_map(map, del);
	*map = ft_hash_init(size);
}
