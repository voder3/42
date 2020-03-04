/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fddel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:58:39 by guaubret          #+#    #+#             */
/*   Updated: 2019/01/14 17:25:43 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_fddel(t_file **f_list, int fd)
{
	t_file	*tmp;
	t_file	*curr;

	curr = *f_list;
	if ((*f_list)->fd == fd)
	{
		ft_strdel(&((*f_list)->content));
		tmp = (*f_list)->next;
		free(*f_list);
		*f_list = tmp;
	}
	else
		while (curr->next)
		{
			tmp = curr->next;
			if (tmp->fd == fd)
			{
				ft_strdel(&(tmp->content));
				curr->next = tmp->next;
				free(tmp);
				break ;
			}
			curr = tmp;
		}
}
