/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:45:02 by artderva          #+#    #+#             */
/*   Updated: 2020/06/15 19:50:24 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_unsetenv(t_msh *msh)
{
	t_list	*env;
	t_list	*prev;

	env = msh->env_var;
	prev = NULL;
	if (!msh->input[1])
		return (ft_error(NULL, "unsetenv: wrong options"));
	while (env)
	{
		if (!ft_strcmp(msh->input[1], (((t_var *)(env->content))->tab[0])))
		{
			if (!prev)
				msh->env_var = env->next;
			else
				prev->next = env->next;
			free(((t_var *)(env->content))->tab[0]);
			free(((t_var *)(env->content))->tab[1]);
			free(((t_var *)(env->content))->tab);
			free(env);
			return (0);
		}
		prev = env;
		env = env->next;
	}
	return (ft_error(msh->input[1], ": no environment variable"));
}

int		ft_setenvlist(t_list **list, char **envp)
{
	int		i;
	t_var	env;

	i = 0;
	*list = NULL;
	while (envp[i])
	{
		if (!(env.tab[0] = ft_strcut(envp[i], "=", 1)))
			ft_ex(NULL, "memomy allocation fail");
		if (!(env.tab[1] = ft_strcut(envp[i], "=", 2)))
			ft_ex(NULL, "memomy allocation fail");
		ft_lst_push_back(list, &env, sizeof(t_var));
		i++;
	}
	return (1);
}

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
