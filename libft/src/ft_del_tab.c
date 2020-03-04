/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walden <walden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:15:42 by walden          #+#    #+#             */
/*   Updated: 2019/12/03 20:02:12 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_del_tab(void **tab)
{
	char	**target;
	int		i;

	i = 0;
	if (!tab)
		return ;
	target = (char **)tab;
	while (target[i])
		ft_strdel(&target[i++]);
	free(target);
	target = NULL;
	tab = NULL;
}
