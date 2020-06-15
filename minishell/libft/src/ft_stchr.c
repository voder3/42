/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:26:42 by artderva          #+#    #+#             */
/*   Updated: 2020/06/15 17:34:23 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stchr(char *str, int c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		else
			i++;
	}
	if (str[i] == c)
		return (i);
	return (0);
}
