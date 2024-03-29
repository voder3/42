/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:51:06 by artderva          #+#    #+#             */
/*   Updated: 2020/06/19 14:07:38 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	minishell(char *str, t_msh *msh)
{
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
	ft_setenvlist(&msh->env_var, env);
}

int		main(int ac, char **av, char **env)
{
	t_msh	msh;
	char	*line;

	line = NULL;
	(void)ac;
	(void)av;
	ft_init(env, &msh);
	while (1)
	{
		ft_putstr("msh> ");
		if ((get_next_line(0, &line)) == -1)
			ft_ex(NULL, "memomy allocation failed");
		if (line)
		{
			minishell(line, &msh);
			ft_strdel(&line);
			free_struct(&msh);
		}
	}
	return (0);
}
