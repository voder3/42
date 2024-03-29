/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_del_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:16 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:16 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_hash_del_map(t_hash_map **map, void (*del)(void *data))
{
	uint32_t	i;
	t_list		*lst;
	t_list		*tmp;

	i = 0;
	if (!*map || !map)
		return ;
	while (((*map)->size == 1 && i <= (*map)->size)
	|| i < (*map)->size)
	{
		lst = (*map)->slots[i];
		while (lst)
		{
			tmp = lst->next;
			ft_hash_del_list(&lst, del);
			lst = tmp;
		}
		i++;
	}
	free((*map)->slots);
	ft_memdel((void **)map);
}
