/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:18 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:18 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstnew;

	if (!(lstnew = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		lstnew->data = NULL;
		lstnew->size = 0;
	}
	else
	{
		if (!(lstnew->data = malloc(content_size)))
		{
			free(lstnew);
			return (NULL);
		}
		lstnew->data = ft_memcpy(lstnew->data, content, content_size);
		lstnew->size = content_size;
	}
	lstnew->next = NULL;
	return (lstnew);
}
