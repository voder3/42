/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:54:05 by artderva          #+#    #+#             */
/*   Updated: 2020/03/02 19:18:37 by artderva         ###   ########.fr       */
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

/*t_env   *ft_setenvlist(char **env)
{
	int             i;
	t_env   *ret;
	t_env   *tmp;
	t_env   *new;
	i = 0;
	if (env[i] && !(ret = malloc(sizeof(t_env))))
		return (0);
	tmp = ret;
	tmp->name = ft_strcut(env[i], "=", 1);
	tmp->value = ft_strcut(env[i], "=", 2);
	tmp->next = NULL;
	i++;
	while (env[i])
	{
		if (!(new = malloc(sizeof(t_env))))
			return (0);
		new->name = ft_strcut(env[i], "=", 1);
		new->value = ft_strcut(env[i], "=", 2);
		new->next = NULL;
		tmp->next = new;
		tmp = tmp->next;
		i++;
	}
	return (ret);
} */

void	ft_lst_push_back(t_list **begin, void *content, size_t content_size)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *begin;
	if (!(new = ft_lstnew(content, content_size)))
		return ;
	if (*begin)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*begin = new;
}

int		ft_setenvlist(t_list **list, char **envp)
{
	int		i;
	t_var	env;
	
	i = 0;
	*list = NULL;
	while (envp[i])
	{
		env.tab[0] = ft_strcut(envp[i], "=", 1);
		env.tab[1] = ft_strcut(envp[i], "=", 2);
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

/*char	**ft_unsetenvlist(t_env *env)
{
	char	**tab;
	int		n;
	int		j;

	n = 0;
	while (env && n++)
		env = env->next;
	if (!(tab = (char**)malloc(sizeof(char *) * n + 1)))
		return (NULL);
	n = 0;
	while (env)
	{
		if (!(tab[n] = ft_strjnlst(env->name, env->value)))
			return (NULL);
		env = env->next;
		n++;
	}
	tab[n] = NULL;
	return (tab);
}*/
