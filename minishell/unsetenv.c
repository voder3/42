/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walden <walden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:07:19 by walden          #+#    #+#             */
/*   Updated: 2019/11/29 04:18:49 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			unsetenv_find(void *elem, void *var)
{
	if (ft_strcmp(((t_var *)elem)->tab[0], (char *)var) == 0)
		return (1);
	return (0);
}

void		unsetenv_del(void *delete)
{
	ft_del_tab(((void **)((t_var *)delete)->tab));
	free(delete);
}

//int			ft_unsetenv(t_list **lst, char *var)
int			ft_unsetenv(t_msh *msh)
{
	t_list **lst;
	char	*var;

	var = msh->input[1];
	lst = &(msh->env_var);
	ft_lstdelif(lst, var, unsetenv_find, unsetenv_del); //changer return pour posix
	return (0);
}


/*
 *void		unsetenv_del(void *delete)
 *{
 *    t_var *tmp;
 *
 *    tmp = ((t_list *)delete)->content;
 *    ft_del_tab((void **)tmp->tab);
 *    ft_memdel((void **)&tmp);
 *    ft_memdel(&delete);
 *}
 */
/*
 *int			ft_unsetenv(t_list **lst, char *var)
 *{
 *     return (ft_lstdelif(lst, var, unsetenv_find, unsetenv_del));
 *}
 */
