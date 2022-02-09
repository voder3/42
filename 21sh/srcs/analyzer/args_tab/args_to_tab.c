/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:12 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:12 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "analyzer.h"

void		**args_to_tab(t_list *lst, char *cmd)
{
	void	**tab;
	t_list	*index;
	int		i;

	index = lst;
	i = 1;
	while ((index = index->next))
		i++;
	if (!(tab = ft_memalloc(sizeof(void *) * (i + 2))))
		exit(EXIT_FAILURE);
	index = lst;
	i = 1;
	tab[0] = cmd;
	while (index)
	{
		tab[i] = index->data;
		index = index->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
