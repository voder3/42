/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:18 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:18 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **begin, void *content, size_t content_size)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *begin;
	if (!(new = ft_lstnew(content, content_size)))
		return ;
	if (*begin)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*begin = new;
}
