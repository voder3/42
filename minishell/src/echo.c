/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 19:11:26 by artderva          #+#    #+#             */
/*   Updated: 2020/06/05 21:48:05 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(t_msh *msh)
{
	int	i;

	i = 1;
	while ((msh->input[i]))
	{
		ft_putstr(msh->input[i++]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	return (0);
}
