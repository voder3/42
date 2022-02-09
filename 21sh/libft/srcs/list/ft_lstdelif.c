/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:18 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:18 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		manage_elem(t_list **begin, t_list *target, t_list *previus,
		void (*del)(void *, size_t))
{
	if (target == *begin)
		*begin = (*begin)->next;
	else
		previus->next = target->next;
	ft_lstdelone(&target, del);
	return (0);
}

int				ft_lstdelif(t_list **begin, void *data,
		int (*f)(void *, void *), void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *previus;

	if (!*begin || !begin)
		return (-1);
	tmp = *begin;
	while (tmp && f(tmp->data, data) != 1)
	{
		previus = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return (1);
	return (manage_elem(begin, tmp, previus, del));
}
