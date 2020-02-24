/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walden <walden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:09:08 by walden          #+#    #+#             */
/*   Updated: 2020/01/22 17:45:18 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_echo(t_msh *msh)
{
	int ac = 1;

	if (msh->input[ac])
	{
		while ((msh->input[ac]))
		{
			ft_putstr(msh->input[ac++]);
			ft_putchar(' ');
		}
	}
	write(1, "\n", 1);                 // free msh->input ??????????//
	return (0);
}
