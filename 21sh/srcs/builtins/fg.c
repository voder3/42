/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:13 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:13 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "struct.h"

uint8_t		ft_fg(t_job *j, t_process *p)
{
	(void)j;
	(void)p;
	ft_dprintf(STDERR_FILENO, "Builtin fg not enable\n");
	return (1);
}
