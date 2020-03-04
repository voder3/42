/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:00:31 by artderva          #+#    #+#             */
/*   Updated: 2019/05/21 18:05:09 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lenm_o(long long n, t_prin fors)
{
	char		*str;

	if (!(fors.lenm) && (!(str = ft_ulltoa_base((unsigned int)n, "01234567"))))
		return (NULL);
	if (fors.lenm == 1
	&& !(str = ft_ulltoa_base((unsigned short)n, "01234567")))
		return (NULL);
	if (fors.lenm == 2 && !(str = ft_ulltoa_base((unsigned char)n, "01234567")))
		return (NULL);
	if (fors.lenm == 3 && !(str = ft_ulltoa_base((unsigned long)n, "01234567")))
		return (NULL);
	if (fors.lenm == 4 && !(str = ft_ulltoa_base(n, "01234567")))
		return (NULL);
	return (str);
}

char	*ft_lenm_u(long long n, t_prin fors)
{
	char		*str;

	if (!(fors.lenm) && !(str = ft_ulltoa_base((unsigned int)n, "0123456789")))
		return (NULL);
	if (fors.lenm == 1
	&& !(str = ft_ulltoa_base((unsigned short)n, "0123456789")))
		return (NULL);
	if (fors.lenm == 2
	&& (!(str = ft_ulltoa_base((unsigned char)n, "0123456789"))))
		return (NULL);
	if (fors.lenm == 3
	&& (!(str = ft_ulltoa_base((unsigned long)n, "0123456789"))))
		return (NULL);
	if (fors.lenm == 4 && (!(str = ft_ulltoa_base(n, "0123456789"))))
		return (NULL);
	return (str);
}

char	*ft_lenm_h(long long n, t_prin fors)
{
	char		*str;

	if (!(fors.lenm)
	&& !(str = ft_ulltoa_base((unsigned int)n, "0123456789abcdef")))
		return (NULL);
	if (fors.lenm == 1
	&& !(str = ft_ulltoa_base((unsigned short)n, "0123456789abcdef")))
		return (NULL);
	if (fors.lenm == 2
	&& (!(str = ft_ulltoa_base((unsigned char)n, "0123456789abcdef"))))
		return (NULL);
	if (fors.lenm == 3
	&& (!(str = ft_ulltoa_base((unsigned long)n, "0123456789abcdef"))))
		return (NULL);
	if (fors.lenm == 4 && (!(str = ft_ulltoa_base(n, "0123456789abcdef"))))
		return (NULL);
	return (str);
}

char	*ft_lenm_hx(long long n, t_prin fors)
{
	char		*str;

	if (!(fors.lenm)
	&& !(str = ft_ulltoa_base((unsigned int)n, "0123456789ABCDEF")))
		return (NULL);
	if (fors.lenm == 1
	&& !(str = ft_ulltoa_base((unsigned short)n, "0123456789ABCDEF")))
		return (NULL);
	if (fors.lenm == 2
	&& (!(str = ft_ulltoa_base((unsigned char)n, "0123456789ABCDEF"))))
		return (NULL);
	if (fors.lenm == 3
	&& (!(str = ft_ulltoa_base((unsigned long)n, "0123456789ABCDEF"))))
		return (NULL);
	if (fors.lenm == 4 && (!(str = ft_ulltoa_base(n, "0123456789ABCDEF"))))
		return (NULL);
	return (str);
}
