/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:26:03 by artderva          #+#    #+#             */
/*   Updated: 2019/05/21 18:05:00 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_tab(int i, va_list ap, t_prin fors, char **prin)
{
	int(*ft_atos[11])(va_list, t_prin, char **);

	ft_atos[0] = &ft_prchar;
	ft_atos[1] = &ft_prstr;
	ft_atos[2] = &ft_prpoi;
	ft_atos[3] = &ft_prnbr;
	ft_atos[4] = &ft_prnbr;
	ft_atos[5] = &ft_proct;
	ft_atos[6] = &ft_prund;
	ft_atos[7] = &ft_prhex;
	ft_atos[8] = &ft_prhem;
	ft_atos[9] = &ft_prflo;
	ft_atos[10] = &ft_prper;
	return (ft_atos[i](ap, fors, prin));
}

int		ft_dis(va_list ap, t_prin fors, char **prin)
{
	int		i;
	char	hey[12];

	i = 0;
	ft_strcpy(hey, "cspdiouxXf%");
	if (!(ft_strchr("cspdiouxXf%", fors.type)))
		return (-1);
	while (fors.type != hey[i])
		i++;
	return (ft_tab(i, ap, fors, prin));
}
