/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:58:56 by artderva          #+#    #+#             */
/*   Updated: 2018/11/21 19:53:48 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(int nbr)
{
	int n;

	n = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		n++;
	}
	while (nbr > 0)
	{
		n++;
		nbr /= 10;
	}
	return (n);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		k;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	k = len(n);
	if (!(str = (char *)malloc(sizeof(char) * k + 1)))
		return (NULL);
	str[0] = '-';
	str[k] = '\0';
	n = n < 0 ? -n : n;
	while (n > 0)
	{
		str[k - 1] = n % 10 + 48;
		n = n / 10;
		k--;
	}
	return (str);
}
