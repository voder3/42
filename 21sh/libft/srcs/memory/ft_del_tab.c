/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:18 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:18 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_del_tab(void **tab)
{
	char	**target;
	int		i;

	i = 0;
	if (!tab || !*tab)
		return ;
	target = (char **)tab;
	while (target[i])
		ft_strdel(&target[i++]);
	free(target);
}
