/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:43:23 by artderva          #+#    #+#             */
/*   Updated: 2020/03/02 18:06:29 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_builtin(t_msh *msh)
{
	if (!(ft_strcmp(msh->input[0], "echo")))
		return (ft_echo(msh));
	else if (!(ft_strcmp(msh->input[0], "cd")))
		return (ft_call_cd(msh));
	else if (!(ft_strcmp(msh->input[0], "setenv")))
		return (ft_setenv(msh));
	else if (!(ft_strcmp(msh->input[0], "unsetenv")))
		return (ft_unsetenv(msh));
	else if (!(ft_strcmp(msh->input[0], "env")))
		return (ft_env(msh));
	else if (!(ft_strcmp(msh->input[0], "exit")))
		return (ft_exit(msh));
	return (-1);	
}
