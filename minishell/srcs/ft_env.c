/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:54:05 by artderva          #+#    #+#             */
/*   Updated: 2020/06/15 19:37:11 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_env(t_list *env)
{
	while (env)
	{
		ft_printf("%s=%s\n", ((t_var *)(env->content))->tab[0],
		((t_var *)(env->content))->tab[1]);
		env = env->next;
	}
}

void	ft_create_env(t_list **l, t_var env)
{
	char	**t;

	if (!(t = (char **)malloc(sizeof(char *) * 2)))
		ft_ex(NULL, "memomy allocation fail");
	if (!(t[0] = ft_strjoin(env.tab[0], "=")))
		ft_ex(NULL, "memomy allocation fail");
	if (!(t[0] = ft_strjoin1(t[0], env.tab[1])))
		ft_ex(NULL, "memomy allocation fail");
	t[1] = NULL;
	ft_setenvlist(l, t);
	ft_del_tab((void **)t);
}

void	add_env_to_lst(t_list *l, t_var env, int overw)
{
	t_var	tmp;

	while (l)
	{
		if (!(ft_strcmp(env.tab[0], ((t_var *)(l->content))->tab[0])))
		{
			if (overw)
			{
				ft_strdel(&((t_var *)(l->content))->tab[1]);
				if (!(((t_var *)(l->content))->tab[1] = ft_strdup(env.tab[1])))
					ft_ex(NULL, "memomy allocation fail");
			}
			break ;
		}
		if (!l->next)
		{
			if (!(tmp.tab[0] = ft_strdup(env.tab[0])))
				ft_ex(NULL, "memomy allocation fail");
			if (!(tmp.tab[1] = ft_strdup(env.tab[1])))
				ft_ex(NULL, "memomy allocation fail");
			ft_lst_push_back(&l, &tmp, sizeof(t_var));
		}
		l = l->next;
	}
}

int		ft_setenv(t_msh *msh)
{
	t_list	*lst;
	t_var	env;
	int		overw;

	if (!msh->input[1] || !msh->input[2])
		return (ft_error(NULL, "setenv: wrong options"));
	if (!(env.tab[0] = msh->input[1]))
		ft_ex(NULL, "memomy allocation fail");
	if (!(env.tab[1] = msh->input[2]))
		ft_ex(NULL, "memomy allocation fail");
	overw = 0;
	if (msh->input[3])
		overw = ft_atoi(msh->input[3]);
	lst = msh->env_var;
	if (!lst)
		ft_create_env(&msh->env_var, env);
	else
		add_env_to_lst(lst, env, overw);
	return (0);
}

int		ft_env(t_msh *msh)
{
	ft_print_env(msh->env_var);
	return (0);
}
