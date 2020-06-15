/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 20:08:24 by artderva          #+#    #+#             */
/*   Updated: 2020/06/15 19:50:40 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_error(char *s1, char *s2)
{
	ft_putstr_fd("msh: ", 2);
	if (s1)
		ft_putstr_fd(s1, 2);
	ft_putendl_fd(s2, 2);
	return (1);
}

void	ft_ex(char *s1, char *s2)
{
	ft_putstr_fd("msh: ", 2);
	if (s1)
		ft_putstr_fd(s1, 2);
	ft_putendl_fd(s2, 2);
	exit(EXIT_FAILURE);
}

void	del_struct_tvar(void *del, size_t u)
{
	t_var	*v;

	(void)u;
	v = del;
	free((void **)v->tab[0]);
	free((void **)v->tab[1]);
	free(v);
}

void	free_struct(t_msh *data)
{
	ft_del_tab((void **)data->input);
}

int		ft_err_fork(void)
{
	ft_putendl_fd("msh : execution failed", 2);
	exit(EXIT_FAILURE);
	return (0);
}
