/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeltail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:18 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:18 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdeltail(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*last;
	t_list	*curr;

	if (!alst || !*alst)
		return ;
	last = *alst;
	if (!last->next)
	{
		ft_lstdelone(alst, del);
		return ;
	}
	curr = last->next;
	while (curr->next)
	{
		last = curr;
		curr = curr->next;
	}
	last->next = NULL;
	ft_lstdelone(&curr, del);
}
