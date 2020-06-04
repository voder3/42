/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:54:05 by artderva          #+#    #+#             */
/*   Updated: 2020/06/04 20:40:38 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getenv(t_list *env, char *name)
{
	char	*res;
	res = NULL;

	while (env && !res)
	{
		if (!ft_strcmp(name,((t_var *)(env->content))->tab[0]))
			res = ((t_var *)(env->content))->tab[1];
		env = env->next;
	}
	return (res);
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

char	*ft_strjnlst(char *s1, char *s2)
{
	char	*str;

	if (!(str = ft_strjoin1(s1, "=")))
		return (NULL);
	if (!(str = ft_strjoin2(str, s2)))
		return (NULL);
	return (str);
}

void    ft_print_env(t_list *env)
{
	while (env)
	{
		ft_printf("%s=%s\n", ((t_var *)(env->content))->tab[0],
		((t_var *)(env->content))->tab[1]);
		env = env->next;
	}
}

int	ft_setenv(t_msh *msh)
{
	t_list	*lst;
	t_var	env;
	int	overw;

	if (!msh->input[1]  || !msh->input[2])
	{
		ft_printf("setenv: wrong options\n");
		return (1);
	}
	env.tab[0] = ft_strdup(msh->input[1]);
	env.tab[1] = ft_strdup(msh->input[2]); // leak
	overw = 0;
	if (msh->input[3])
		overw = ft_atoi(msh->input[3]);
	lst = msh->env_var;
	while (lst)
	{
		if (!(ft_strcmp(env.tab[0], ((t_var *)(lst->content))->tab[0])))
		{
			if (overw)
				((t_var *)(lst->content))->tab[1] = env.tab[1];
			break;
		}
		if (!lst->next)
			ft_lst_push_back(&lst, &env, sizeof(t_var));
		lst = lst->next;
	}
	// free env??
//	ft_strdel(&env.tab[0]);
//	ft_strdel(&env.tab[1]);

	return (0);
}

int	ft_env(t_msh *msh)
{
	ft_print_env(msh->env_var);
	return (0);
}
