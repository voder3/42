/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walden <walden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:33:20 by walden          #+#    #+#             */
/*   Updated: 2020/01/07 18:57:21 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


static int		exit_opt(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (1);
		s++;
	}
	return (0);
}

int				ft_exit(t_msh *msh)
{
	char	*err_arg;
	char	*err_num1;
	char	*err_num2;

	err_arg = "exit\nMSH: exit: too many arguments\n";
	err_num1 = "exit\nMSH: exit: ";
	err_num2= ": numeric argument required\n";
	if (msh->input[1])
	{
		if (exit_opt(msh->input[1]))
		{
			ft_putstr_fd(err_num1, 2);
			ft_putstr_fd(msh->input[1], 2);
			ft_putstr_fd(err_num2, 2);
			exit(255);
		}
		if (msh->input[2])
		{
			ft_putstr_fd(err_arg, 2);
			return (1);
		}
		msh->lr = ft_atoi(msh->input[1]);
	}
	exit(msh->lr);
}
