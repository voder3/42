/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_del_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:16 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:16 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_hash_del_list(t_list **lst, void (*del)(void *))
{
	t_hash_node	*node;

	if ((node = (t_hash_node *)(*lst)->data))
	{
		ft_strdel(&node->key);
		if (del)
			del(node->data);
		free(node);
	}
	free(*lst);
}
