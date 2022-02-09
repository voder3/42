/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:16 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:16 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"

int32_t			job_has_finish(void *job, void *status)
{
	t_job	*j;
	uint8_t	ending_status;

	j = job;
	ending_status = *((uint8_t *)(status));
	if (j->status & ending_status)
		return (1);
	return (0);
}
