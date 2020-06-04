/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 20:08:24 by artderva          #+#    #+#             */
/*   Updated: 2020/06/04 21:04:28 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(char *s1, char *s2)
{
	ft_putstr_fd("msh: ", 2);
	if (s1)
		ft_putstr_fd(s1, 2);
	ft_putendl_fd(s2, 2);
	return (-1);
}

void	ft_ex(char *s1, char *s2)
{
	ft_putstr_fd("msh: ", 2);
	if (s1)
		ft_putstr_fd(s1, 2);
	ft_putendl_fd(s2, 2);
	exit(EXIT_FAILURE);
} // aussi libérer la structure??

void	del_struct_tvar(void *del, size_t u)
{
	t_var	*v;

	(void)u;
	v = del;
	ft_del_tab((void **)v->tab);
	free(v);
}

void	free_struct(t_msh *data)
{
	ft_del_tab((void **)data->input);
	ft_del_tab((void **)data->envp);
	ft_lstdel(&data->env_var, del_struct_tvar);
}
