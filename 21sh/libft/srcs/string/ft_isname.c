/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isname.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:20 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:20 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isname(char *str)
{
	if (ft_isdigit(*str))
		return (0);
	while (*str)
	{
		if (!ft_isalnum((int)*str) && *str != '_')
			return (0);
		str++;
	}
	return (1);
}
