/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_oux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:07:18 by artderva          #+#    #+#             */
/*   Updated: 2019/05/21 18:04:31 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_lenw_oct(t_prin fors, char *str, int len)
{
	char	*tmp;

	if (!(tmp = ft_strnew(fors.lenw - len)))
		return (ft_free(str));
	if (fors.flag[1] == '1' && fors.prec == -1 && fors.flag[2] != '1')
		ft_memset((void *)tmp, '0', fors.lenw - len);
	else
		ft_memset((void *)tmp, ' ', fors.lenw - len);
	if (!(str = ft_minus(fors, str, tmp)))
		return (ft_free2(str, tmp));
	return (str);
}

int			ft_proct(va_list ap, t_prin fors, char **prin)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = va_arg(ap, long long);
	if (n == 0 && fors.flag[0] == '0' && fors.prec == 0)
	{
		if (!(str = ft_strnew(0)))
			return (-1);
	}
	else if (!(str = ft_lenm_o(n, fors)))
		return (-1);
	if (fors.flag[0] == '1' && n && (!(str = ft_straddcb('0', str))))
		return (ft_free3(str));
	len = ft_strlen(str);
	if (fors.prec > len && (!(str = ft_addzero(str, fors.prec - len))))
		return (ft_free3(str));
	if (fors.lenw > (len = ft_strlen(str)))
	{
		if (!(str = ft_lenw_oct(fors, str, len)))
			return (ft_free3(str));
	}
	if (!(*prin = ft_sjoin(*prin, str)))
		return (ft_free3(str));
	return (1);
}

int			ft_prund(va_list ap, t_prin fors, char **prin)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = va_arg(ap, long long);
	if (n == 0 && fors.prec == 0)
		return (1);
	if (!(str = ft_lenm_u(n, fors)))
		return (-1);
	len = ft_strlen(str);
	if (fors.prec > len && (!(str = ft_addzero(str, fors.prec - len))))
		return (ft_free3(str));
	len = ft_strlen(str);
	if (fors.lenw > len)
	{
		if (!(str = ft_lenw_oct(fors, str, len)))
			return (ft_free3(str));
	}
	if (!(*prin = ft_sjoin(*prin, str)))
		return (ft_free3(str));
	return (1);
}

static char	*ft_lenw_hex(t_prin fors, char *str, int len)
{
	char	*tmp;

	if (!(tmp = ft_strnew(fors.lenw - len)))
		return (ft_free(str));
	if (fors.flag[1] == '1' && fors.prec == -1 && fors.flag[2] != '1')
		ft_memset((void *)tmp, '0', fors.lenw - len);
	else
		ft_memset((void *)tmp, ' ', fors.lenw - len);
	if (fors.flag[0] == '1')
	{
		if (fors.flag[1] == '1')
		{
			if (fors.flag[2] != '1' && (!(tmp = ft_strjoin2("0x", tmp))))
				return (ft_free2(str, tmp));
			if (fors.flag[2] == '1' && (!(str = ft_strjoin2("0x", str))))
				return (ft_free2(str, tmp));
		}
		if (fors.flag[1] != '1' && (!(str = ft_strjoin2("0x", str))))
			return (ft_free2(str, tmp));
	}
	if (!(str = ft_minus(fors, str, tmp)))
		return (ft_free2(str, tmp));
	return (str);
}

int			ft_prhex(va_list ap, t_prin fors, char **prin)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = va_arg(ap, unsigned long long);
	if (n == 0 && fors.prec == 0 && (!(str = ft_strnew(0))))
		return (-1);
	if ((n || fors.prec != 0) && !(str = ft_lenm_h(n, fors)))
		return (ft_free3(str));
	len = ft_strlen(str);
	if (fors.prec > len && (!(str = ft_addzero(str, fors.prec - len))))
		return (ft_free3(str));
	len = ft_strlen(str);
	len = fors.flag[0] == '1' ? len + 2 : len;
	if (fors.lenw > len && (!(str = ft_lenw_hex(fors, str, len))))
		return (ft_free3(str));
	else if (fors.lenw <= len && n && fors.flag[0] == '1' &&
			(!(str = ft_strjoin2("0x", str))))
		return (ft_free3(str));
	if (!(*prin = ft_sjoin(*prin, str)))
		return (ft_free3(str));
	return (1);
}
