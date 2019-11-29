/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:43:23 by artderva          #+#    #+#             */
/*   Updated: 2019/11/29 04:15:26 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_built(int i, t_msh *msh)
{
	int(*ft_bbbtin[6])(t_msh *);

	ft_bbbtin[0] = &ft_echo;
//	ft_bbbtin[1] = &ft_cd;
	ft_bbbtin[2] = &ft_setenv;
	ft_bbbtin[3] = &ft_unsetenv;
	ft_bbbtin[4] = &ft_env;
	ft_bbbtin[5] = &ft_exit;
	return (ft_bbbtin[i](msh));
}

int		find_builtin(char *str, t_msh *msh)
{
	char	*buil[6];
	int		i;
	pid_t	pid;

	i = 0;
	buil[0] = "echo";
	buil[1] = "cd";
	buil[2] = "setenv";
	buil[3] = "unsetenv";
	buil[4] = "env";
	buil[5] = "exit";

	while (i < 6)
	{
		if (!(ft_strcmp(msh->input[0], buil[i])))
		{
			ft_built(i, msh);;
		}
		i++;
	}
	return (i);
}

//int		ft_is_built(char *str, t_msh *msh)
//{
//	
//}
