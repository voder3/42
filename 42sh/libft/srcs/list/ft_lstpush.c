/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:09:53 by user42            #+#    #+#             */
/*   Updated: 2020/07/10 15:09:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list **alst, void *content, size_t content_size)
{
	t_list	*new;

	if (!(new = ft_memalloc(sizeof(t_list))))
		return (NULL);
	new->size = content_size;
	new->data = content;
	new->next = NULL;
	ft_lstaddtail(alst, new);
	return (new);
}
