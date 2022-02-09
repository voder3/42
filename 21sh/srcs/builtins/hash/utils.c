/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:14 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:14 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hash_usage_error(void)
{
	ft_dprintf(2, "hash: usage: hash [-r] [name ...]\n");
}

int		hash_not_found(char *cmd)
{
	ft_dprintf(2, "hash: no such command: %s\n", cmd);
	return (0);
}
