/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:22 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:22 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **t)
{
	char	**dup;
	int		i;

	dup = NULL;
	if (t)
	{
		i = 0;
		while (t[i])
			i++;
		if (!(dup = (char **)malloc(sizeof(char*) * (i + 1))))
			exit(EXIT_FAILURE);
		dup[i] = NULL;
		while (i-- > 0)
			dup[i] = ft_strdup(t[i]);
	}
	return (dup);
}
