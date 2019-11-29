/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:51:06 by artderva          #+#    #+#             */
/*   Updated: 2019/11/29 03:49:10 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/minishell.h"
#include <stdio.h>

int		yoyo(char *str, t_msh *msh)
{
	char	**tab;
	char	*pro;
	int		i;

	if (!(msh->input = ft_strsplit(str, ' ')))
		return (0);
	if (!(msh->path = ft_getenv(msh->envl, "PATH")))
		return (0);
	if (!(msh->input = ft_exp_str(msh->input, msh->envl))) //exp_str segfot lol
		return (0);
	find_builtin(str, msh);
	//ft_is_exec(str, msh); //  a faire apres verif des builtine
	return (0);
}

t_msh	ft_init(char **env)
{
	t_msh	msh;

	msh.input = NULL;
	msh.path = NULL;
	msh.envl = ft_setenvlist(env); // a securiZZZZZZZZZZZ

	return (msh);
}

int		main(int ac, char **av, char **env)
{
	t_msh	msh;
	char	*line;
	int		i;
	char	*pro;

	i = 1;
	msh = ft_init(env);
	while (i)
	{
		ft_putstr("VSH> ");
		if ((i = get_next_line(0, &line)) == -1)
			return (0);
		if (*line)
			yoyo(line, &msh);
		ft_strdel(&line);
	}
	return 0;
}
