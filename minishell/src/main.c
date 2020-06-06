/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:51:06 by artderva          #+#    #+#             */
/*   Updated: 2020/06/06 00:14:40 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	minishell(char *str, t_msh *msh)
{
	char	**tab;
	char	*pro;

	if (!(msh->input = ft_split(str, " \t")))
		ft_ex(NULL, "memomy allocation fail");
	if (!(msh->input[0]))
		return ;
	if (!(msh->input = ft_exp_str(msh->input, msh->env_var)))
		ft_ex(NULL, "memomy allocation fail");
	if (find_builtin(msh) < 0)
		ft_is_exec(msh);
}

void	ft_init(char **env, t_msh *msh)
{
	msh->input = NULL;
	msh->envp = env;
	ft_setenvlist(&msh->env_var, env);
}

int		main(int ac, char **av, char **env)
{
	t_msh	msh;
	char	*line;
	int		i;

	i = 1;
	line = NULL;
	ft_init(env, &msh);
	while (i)
	{
		ft_putstr("msh> ");
		if ((i = get_next_line(0, &line)) == -1)
			ft_ex(NULL, "memomy allocation fail");
		if (*line)
			minishell(line, &msh);
		ft_strdel(&line);
	}
	return (0);
}
