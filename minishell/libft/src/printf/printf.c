/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:59:48 by artderva          #+#    #+#             */
/*   Updated: 2019/07/31 17:59:06 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_print2(char *str, char *prin, va_list ap)
{
	t_prin	fors;

	while (*str)
		if (*str == '%' && str++)
		{
			if (ft_getfs(&str, &fors) < 0 || ft_dis(ap, fors, &prin) == -1)
				return (ft_free(prin));
			while (*str != fors.type)
				str++;
			str++;
		}
		else
		{
			if (!(prin = ft_straddc(prin, *str)))
				return (ft_free(prin));
			str++;
		}
	return (prin);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*all;
	char	*prin;
	int		ret;

	if (!(prin = ft_strnew(0)))
		return (-1);
	all = (void *)format;
	va_start(ap, format);
	if (!(prin = ft_print2(all, prin, ap)))
		return (ft_free3(prin));
	ft_putstr(prin);
	ret = ft_strlen(prin);
	ft_strdel(&prin);
	return (ret);
}
