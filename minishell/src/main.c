/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:51:06 by artderva          #+#    #+#             */
/*   Updated: 2020/03/02 18:56:46 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/minishell.h"
#include <stdio.h>

int		yoyo(char *str, t_msh *msh)
{
	char	**tab;
	char	*pro;
	int		i;

	if (!(msh->input = ft_strsplit(str, ' ')))
		return (0);
	if (!(msh->path = ft_getenv(msh->env_var, "PATH")))
		return (0);
	if (!(msh->input = ft_exp_str(msh->input, msh->env_var))) //exp_str segfot lol
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
	ft_setenvlist(&msh.env_var, env); // a securiZZZZZZZZZZZ
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
	ft_putendl("CC");
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
