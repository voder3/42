/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:54:05 by artderva          #+#    #+#             */
/*   Updated: 2020/06/05 22:08:04 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getenv(t_list *env, char *name)
{
	char	*res;

	res = NULL;
	while (env && !res)
	{
		if (!ft_strcmp(name, ((t_var *)(env->content))->tab[0]))
			res = ((t_var *)(env->content))->tab[1];
		env = env->next;
	}
	return (res);
}

void	ft_print_env(t_list *env)
{
	while (env)
	{
		ft_printf("%s=%s\n", ((t_var *)(env->content))->tab[0],
		((t_var *)(env->content))->tab[1]);
		env = env->next;
	}
}

void	add_env_to_lst(t_list *lst, t_var env, int overw)
{
	while (lst)
	{
		if (!(ft_strcmp(env.tab[0], ((t_var *)(lst->content))->tab[0])))
		{
			if (overw)
				((t_var *)(lst->content))->tab[1] = env.tab[1];
			break ;
		}
		if (!lst->next)
			ft_lst_push_back(&lst, &env, sizeof(t_var));
		lst = lst->next;
	}
}

int		ft_setenv(t_msh *msh)
{
	t_list	*lst;
	t_var	env;
	int		overw;

	if (!msh->input[1] || !msh->input[2])
		return (ft_error(NULL, "setenv: wrong options"));
	if (!(env.tab[0] = ft_strdup(msh->input[1])))
		ft_ex(NULL, "memomy allocation fail");
	if (!(env.tab[1] = ft_strdup(msh->input[2])))
		ft_ex(NULL, "memomy allocation fail");
	overw = 0;
	if (msh->input[3])
		overw = ft_atoi(msh->input[3]);
	lst = msh->env_var;
	add_env_to_lst(lst, env, overw);
	// free env??
	return (0);
}

int		ft_env(t_msh *msh)
{
	ft_print_env(msh->env_var);
	return (0);
}
