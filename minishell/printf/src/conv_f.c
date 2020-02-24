/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:43:38 by artderva          #+#    #+#             */
/*   Updated: 2019/07/16 16:52:54 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_dec_f(long long d, unsigned long long prec, long long cp)
{
	char		*tmp;

	if (!(tmp = ft_lltoa(d)))
		return (NULL);
	while (cp > 0 && cp--)
		if (!(tmp = ft_straddc(tmp, '0')))
			return (ft_free(tmp));
	while (ft_strlen(tmp) < prec)
		if (!(tmp = ft_straddcb('0', tmp)))
			return (ft_free(tmp));
	return (tmp);
}

static char	*ft_lftoa(long double n, unsigned long long prec)
{
	char		*str;
	long double	dec;
	long long	d;
	long long	cp;
	char		*tmp;

	cp = prec;
	d = n;
	if (!(str = ft_lltoa(d)))
		return (NULL);
	dec = n - d;
	while (dec < 922337203685477580 && cp--)
		dec *= 10;
	d = dec + 0.5;
	if (!prec)
		return (str);
	if (!(str = ft_straddc(str, '.')))
		return (ft_free(str));
	if (!(tmp = ft_dec_f(d, prec, cp)))
		return (ft_free(str));
	if (!(str = ft_sjoin(str, tmp)))
		return (ft_free(str));
	return (str);
}

static char	*ft_lenw_f(t_prin fors, char *str)
{
	char		*tmp;

	if (!(tmp = ft_strnew(fors.lenw - ft_strlen(str))))
		return (ft_free(str));
	if (fors.flag[1] == '1' && fors.flag[2] != '1')
		ft_memset((void *)tmp, '0', fors.lenw - ft_strlen(str));
	else
		ft_memset((void *)tmp, ' ', fors.lenw - ft_strlen(str));
	if (!(str = ft_minus(fors, str, tmp)))
		return (ft_free2(str, tmp));
	return (str);
}

int			ft_prflo(va_list ap, t_prin fors, char **prin)
{
	long double	n;
	char		*str;
	int			prec;

	prec = fors.prec == -1 ? 6 : fors.prec;
	if (fors.lenm == 5)
		n = va_arg(ap, long double);
	else
		n = va_arg(ap, double);
	if (!(str = ft_lftoa(n, prec)))
		return (-1);
	if (fors.prec == 0 && fors.flag[0] == '1' && !(str = ft_straddc(str, '.')))
		return (ft_free3(str));
	if ((size_t)fors.lenw > ft_strlen(str) && !(str = ft_lenw_f(fors, str)))
		return (ft_free3(str));
	if (!(*prin = ft_sjoin(*prin, str)))
		return (ft_free3(str));
	return (1);
}

int			ft_prper(va_list ap, t_prin fors, char **prin)
{
	char	*str;

	(void)ap;
	if (fors.lenw > 1)
	{
		if (!(str = ft_strnew(fors.lenw - 1)))
			return (-1);
		if (fors.flag[1] == '1' && fors.prec == -1 && fors.flag[2] != '1')
			ft_memset((void *)str, '0', fors.lenw - 1);
		else
			ft_memset((void *)str, ' ', fors.lenw - 1);
		if (fors.flag[2] == '1' && (!(str = ft_straddcb('%', str))))
			return (ft_free3(str));
		if (fors.flag[2] != '1' && (!(str = ft_straddc(str, '%'))))
			return (ft_free3(str));
		if (!(*prin = ft_sjoin(*prin, str)))
			return (ft_free3(str));
		return (1);
	}
	if (!(*prin = ft_straddc(*prin, '%')))
		return (-1);
	return (1);
}
