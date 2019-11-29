/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walden <walden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:54:41 by walden          #+#    #+#             */
/*   Updated: 2019/11/29 04:18:33 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_print_env_lst(t_list *env) // int juste pour call dans return ?
{
	while (env)
	{
		ft_printf("%s=%s\n", ((t_var *)(env->content))->tab[0], ((t_var *)(env->content))->tab[1]);
		env = env->next;
	}
	return (0);
}

int		env_creat_lst_env(char **input, t_list **new, int ac)
{
	char	*tmp;
	int		i;

	i = ac;
	while (input[ac] && ft_strchr(input[ac], '='))
		ac++;
	if (ac == i)
		return (ac);
	tmp = input[ac];
	input[ac] = NULL;
	ft_list_var_env(new, input+i);
	input[ac] = tmp;
	return (ac);
}

void	ft_join_list(t_list *lst1, t_list **lst2, int refresh)
{
	t_list *tmp;

	if (!lst1)
	{
		lst1 = *lst2;
		return ;
	}
	tmp = lst1;
	while (lst1->next)
		lst1 = lst1->next;
	lst1->next = *lst2;
	if (refresh)
		*lst2 = tmp;
}

//t_list	*ft_copy_list(t_list *lst)
t_list		*env_list_cpy(t_list *lst)
{
	t_list	*cpy;
	char	**envp;

	envp = ft_create_tab_env(lst, 0);
	ft_list_var_env(&cpy, envp);
	ft_del_tab((void **)envp);
	return (cpy);
}

int		ft_env(t_msh *msh)
{
	t_msh	fresh;
	int		ac;
	int		i;
	int		ret;
	char	*tmp;

	i = 0;
	ret = 0;
	ac = 1;
	ft_init_struct(&fresh, NULL);
	if (!msh->input[1])
		return (ft_print_env_lst(msh->env_var));
	while ((ret = ft_getopt(&ac, &i, msh->input, "i")) != -1)
		if (ret == '?') 		// probleme de curseur
			return (ft_printf("env: illegal option -- %c\nusage : env [-i] [utility [argument ...]]\n", msh->input[ac][i])); 		//ecrire sur stdr

	ret = env_creat_lst_env(msh->input, &(fresh.env_var), ac);
	if (ac == 1)
		ft_join_list(env_list_cpy(msh->env_var), &(fresh.env_var), 1);
	ac = ret;
	tmp = ft_tab_to_str((msh->input+ac));
	if (!(msh->input[ac]))
		ft_print_env_lst(fresh.env_var);
	else if (msh_road(&fresh, tmp))
		ft_printf("env: %s: No such file or directory\n", fresh.input[0]);
	ft_strdel(&tmp);
	ft_clear_msh(&fresh, 1);
	return (0);

	// ==> PB si -i => call sans path decouper builtin or not pour appeler ici

	/*
	 *while (fresh.env_var)
	 *{
	 *    printf("%s=%s\n", ((t_var *)(fresh.env_var->content))->tab[0], ((t_var *)(fresh.env_var->content))->tab[1]);
	 *    fresh.env_var = fresh.env_var->next;
	 *}
	 */
	
}
