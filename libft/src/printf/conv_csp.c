/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convcsp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:55:10 by artderva          #+#    #+#             */
/*   Updated: 2019/07/16 18:29:53 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_prchar(va_list ap, t_prin fors, char **prin)
{
	unsigned char	add;
	char			*str;

	add = va_arg(ap, int);
	if (fors.lenw > 1)
	{
		if (!(str = ft_strnew(fors.lenw - 1)))
			return (-1);
		ft_memset((void *)str, ' ', fors.lenw - 1);
		if (fors.flag[2] == '1' && (!(str = ft_straddcb(add, str))))
			return (ft_free3(str));
		if (fors.flag[2] != '1' && (!(str = ft_straddc(str, add))))
			return (ft_free3(str));
		if (!(*prin = ft_sjoin(*prin, str)))
			return (ft_free3(str));
		return (1);
	}
	if (!(*prin = ft_straddc(*prin, (char)add)))
		return (-1);
	return (1);
}

static char	*ft_minus2(t_prin fors, char *str, char *tmp)
{
	if (fors.flag[2] == '1')
	{
		if (!(str = ft_strjoin2(str, tmp)))
			return (ft_free2(str, tmp));
	}
	else
	{
		if (!(str = ft_strjoin1(tmp, str)))
			return (ft_free2(str, tmp));
	}
	return (str);
}

static char	*ft_lenw_str(t_prin fors, char *str, int lens)
{
	char	*tmp;

	if (!(tmp = ft_strnew(fors.lenw - lens)))
		return (NULL);
	ft_memset((void *)tmp, ' ', fors.lenw - lens);
	if (!(str = ft_minus2(fors, str, tmp)))
		return (ft_free2(str, tmp));
	return (str);
}

int			ft_prstr(va_list ap, t_prin fors, char **prin)
{
	char	*str;
	int		lens;
	int		fr;

	fr = 0;
	if (!(str = va_arg(ap, char *)))
		if (++fr && !(str = ft_strdup("(null)")))
			return (-1);
	if (fors.prec != -1 && fors.prec < (lens = ft_strlen(str)))
		if (++fr && !(str = ft_strndup(str, fors.prec)))
			return (-1);
	if (fors.lenw > (lens = ft_strlen(str)))
	{
		if (fr && !(str = ft_lenw_str(fors, str, lens)))
			return (ft_free3(str));
		else if (!fr && ++fr && !(str = ft_lenw_str(fors, str, lens)))
			return (-1);
	}
	if (fr && !(*prin = ft_sjoin(*prin, str)))
		return (ft_free3(str));
	if (!fr && !(*prin = ft_strjoin1(*prin, str)))
		return (-1);
	return (1);
}

int			ft_prpoi(va_list ap, t_prin fors, char **prin)
{
	unsigned long long	n;
	char				*str;
	int					lens;

	n = va_arg(ap, unsigned long long);
	if (!(str = ft_strjoin2("0x", ft_ulltoa_base(n, "0123456789abcdef"))))
		return (-1);
	lens = ft_strlen(str);
	if (fors.lenw > lens)
	{
		if (!(str = ft_lenw_str(fors, str, lens)))
			return (ft_free3(str));
	}
	if (!(*prin = ft_sjoin(*prin, str)))
		return (ft_free3(str));
	return (1);
}
