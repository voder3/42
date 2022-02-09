/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:18 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:18 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lstdst;
	t_list	*begin;
	t_list	*tmp;

	tmp = f(lst);
	lstdst = ft_lstnew(tmp->data, tmp->size);
	if (!lstdst)
		return (NULL);
	begin = lstdst;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		lstdst->next = ft_lstnew(tmp->data, tmp->size);
		if (!lstdst)
			return (NULL);
		lstdst = lstdst->next;
		lst = lst->next;
	}
	return (begin);
}
