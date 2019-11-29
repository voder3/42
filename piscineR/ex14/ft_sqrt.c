/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:09:32 by artderva          #+#    #+#             */
/*   Updated: 2018/11/06 17:17:36 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int sq;

	if (nb > 46340)
		sq = 46340;
	else
		sq = nb;
	while (sq > 0)
	{
		if (sq * sq == nb)
			return (sq);
		else
			sq--;
	}
	return (0);
}
