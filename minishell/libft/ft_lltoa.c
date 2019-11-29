/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:43:53 by artderva          #+#    #+#             */
/*   Updated: 2019/04/10 14:31:49 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_len(long long nb)
{
	int		len;

	len = nb < 0 ? 1 : 0;
	nb = nb < 0 ? -nb : nb;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char		*ft_lltoa(long long nb)
{
	char		*str;
	int			len;

	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	len = ft_len(nb);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[0] = '-';
	nb = nb < 0 ? -nb : nb;
	while (nb > 0)
	{
		str[len - 1] = nb % 10 + 48;
		nb /= 10;
		len--;
	}
	return (str);
}
