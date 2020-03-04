/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:25:00 by artderva          #+#    #+#             */
/*   Updated: 2019/04/10 14:25:09 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ulltoa_base(unsigned long long nb, char *base)
{
	int					len_base;
	int					k;
	char				*str;
	unsigned long long	tmp;

	if (!base)
		return (NULL);
	if (nb == 0)
		return (ft_strdup("0"));
	k = 1;
	tmp = nb;
	len_base = ft_strlen(base);
	while (tmp >= (unsigned long long)len_base)
	{
		tmp /= (unsigned long long)len_base;
		k++;
	}
	if (!(str = ft_strnew(k)))
		return (NULL);
	while (nb > 0)
	{
		str[k-- - 1] = (nb % len_base)[base];
		nb /= len_base;
	}
	return (str);
}
