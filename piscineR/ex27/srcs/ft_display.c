/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:54:23 by artderva          #+#    #+#             */
/*   Updated: 2018/11/07 22:18:21 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int		i;
	char	str[1];

	if (ac < 2)
		write(2, "File name missing.\n", 19);
	if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		if ((i = open(av[1], O_RDONLY)) < 0)
			return (0);
		while (read(i, str, 1) > 0)
			write(1, str, 1);
	}
	return (0);
}
