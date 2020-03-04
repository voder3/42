/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:38:54 by artderva          #+#    #+#             */
/*   Updated: 2019/05/21 18:04:04 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_plus(char *str, t_prin fors)
{
	if (fors.flag[3] == '1' && !(str = ft_straddcb('+', str)))
		return (ft_free(str));
	else if (fors.flag[4] == '1' && !(str = ft_straddcb(' ', str)))
		return (ft_free(str));
	return (str);
}

static char	*ft_lenw_nbr(t_prin fors, char *str, int len)
{
	char	*tmp;

	if (fors.flag[3] == '1' || fors.flag[4] == '1')
		len++;
	if (!(tmp = ft_strnew(fors.lenw - len)))
		return (ft_free(str));
	if (fors.flag[1] == '1' && fors.prec == -1 && fors.flag[2] != '1')
	{
		ft_memset((void *)tmp, '0', fors.lenw - len);
		if (!(tmp = ft_plus(tmp, fors)))
			return (ft_free2(str, tmp));
	}
	else
	{
		ft_memset((void *)tmp, ' ', fors.lenw - len);
		if (!(str = ft_plus(str, fors)))
			return (ft_free2(str, tmp));
	}
	if (!(str = ft_minus(fors, str, tmp)))
		return (ft_free2(str, tmp));
	return (str);
}

static char	*ft_prpos(t_prin fors, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (fors.prec > len && !(str = ft_addzero(str, fors.prec - len)))
		return (ft_free(str));
	len = ft_strlen(str);
	if (fors.lenw <= len)
	{
		if (fors.flag[3] == '1' && !(str = ft_straddcb('+', str)))
			return (ft_free(str));
		else if (fors.flag[3] == '0' && fors.flag[4] == '1' &&
				!(str = ft_straddcb(' ', str)))
			return (ft_free(str));
	}
	else if (!(str = ft_lenw_nbr(fors, str, len)))
		return (ft_free(str));
	return (str);
}

static char	*ft_lenm_n(va_list ap, t_prin fors)
{
	long long	n;
	char		*str;

	n = va_arg(ap, long long);
	if (!(fors.lenm) && (!(str = ft_lltoa((int)n))))
		return (NULL);
	if (fors.lenm == 1 && (!(str = ft_lltoa((short)n))))
		return (NULL);
	if (fors.lenm == 2 && (!(str = ft_lltoa((char)n))))
		return (NULL);
	if (fors.lenm == 3 && (!(str = ft_lltoa((long)n))))
		return (NULL);
	if (fors.lenm == 4 && (!(str = ft_lltoa(n))))
		return (NULL);
	return (str);
}

int			ft_prnbr(va_list ap, t_prin fors, char **prin)
{
	char		*str;

	if (!(str = ft_lenm_n(ap, fors)))
		return (-1);
	if (ft_atoll(str) == 0 && fors.prec == 0)
	{
		if (!(str = ft_strnew(0)))
			return (ft_free3(str));
		if (!(str = ft_prpos(fors, str)))
			return (ft_free3(str));
	}
	else if (ft_atoll(str) >= 0 && (!(str = ft_prpos(fors, str))))
		return (ft_free3(str));
	if (ft_atoll(str) < 0 && (!(str = ft_prneg(str, fors))))
		return (ft_free3(str));
	if (!(*prin = ft_sjoin(*prin, str)))
		return (ft_free3(str));
	return (1);
}
