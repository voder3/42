/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:16 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:16 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_hash_delone(t_hash_map *map, char *key, void (*del)(void *))
{
	t_list		*lst;
	t_list		*tmp;
	uint32_t	hash;
	t_hash_node	*node;

	hash = ft_hash_str(map, key);
	lst = map->slots[hash];
	tmp = NULL;
	while (lst)
	{
		if ((node = (t_hash_node *)lst->data)
		&& ft_strequ(node->key, key))
		{
			if (tmp)
				tmp->next = lst->next;
			else
				map->slots[hash] = lst->next;
			ft_hash_del_list(&lst, del);
			return ;
		}
		tmp = lst;
		lst = lst->next;
	}
}
