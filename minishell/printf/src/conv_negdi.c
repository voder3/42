/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_negdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:41:44 by artderva          #+#    #+#             */
/*   Updated: 2019/05/21 18:04:21 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_neg2(char *str, t_prin fors, int len)
{
	char	*tmp;

	len++;
	if (!(tmp = ft_strnew(fors.lenw - len)))
		return (ft_free(str));
	if (fors.flag[1] == '1' && fors.prec == -1 && fors.flag[2] != '1')
	{
		ft_memset((void *)tmp, '0', fors.lenw - len);
		if (!(tmp = ft_straddcb('-', tmp)))
			return (ft_free2(str, tmp));
		if (!(str = ft_sjoin(tmp, str)))
			return (ft_free2(str, tmp));
	}
	else
	{
		ft_memset((void *)tmp, ' ', fors.lenw - len);
		if (!(str = ft_straddcb('-', str)))
			return (ft_free2(str, tmp));
		if (!(str = ft_minus(fors, str, tmp)))
			return (ft_free2(str, tmp));
	}
	return (str);
}

char		*ft_prneg(char *str, t_prin fors)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	tmp = str;
	if (!(str = ft_strsub(str, 1, len - 1)))
		return (ft_free(str));
	ft_strdel(&tmp);
	len--;
	if (fors.prec > len && (!(str = ft_addzero(str, fors.prec - len))))
		return (ft_free(str));
	len = ft_strlen(str);
	if (fors.lenw <= len && !(str = ft_straddcb('-', str)))
		return (ft_free(str));
	else if (fors.lenw > len && !(str = ft_neg2(str, fors, len)))
		return (ft_free(str));
	return (str);
}

static char	*ft_lenw_hem(t_prin fors, char *str, int len)
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
			if (fors.flag[2] != '1' && (!(tmp = ft_strjoin2("0X", tmp))))
				return (ft_free2(str, tmp));
			if (fors.flag[2] == '1' && (!(str = ft_strjoin2("0X", str))))
				return (ft_free2(str, tmp));
		}
		if (fors.flag[1] != '1' && (!(str = ft_strjoin2("0X", str))))
			return (ft_free2(str, tmp));
	}
	if (!(str = ft_minus(fors, str, tmp)))
		return (ft_free2(str, tmp));
	return (str);
}

int			ft_prhem(va_list ap, t_prin fors, char **prin)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = va_arg(ap, unsigned long long);
	if (n == 0 && fors.prec == 0 && (!(str = ft_strnew(0))))
		return (-1);
	if ((n || fors.prec != 0) && !(str = ft_lenm_hx(n, fors)))
		return (-1);
	len = ft_strlen(str);
	if (fors.prec > len && (!(str = ft_addzero(str, fors.prec - len))))
		return (ft_free3(str));
	len = ft_strlen(str);
	len = fors.flag[0] == '1' ? len + 2 : len;
	if (fors.lenw > len && !(str = ft_lenw_hem(fors, str, len)))
		return (ft_free3(str));
	else if (fors.lenw <= len && n && fors.flag[0] == '1' &&
			(!(str = ft_strjoin2("0X", str))))
		return (ft_free3(str));
	if (!(*prin = ft_sjoin(*prin, str)))
		return (ft_free3(str));
	return (1);
}
