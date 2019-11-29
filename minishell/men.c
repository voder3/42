/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   men.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:13:15 by artderva          #+#    #+#             */
/*   Updated: 2019/11/28 23:44:50 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "includes/minishell.h"

int main(int ac, char **av, char **env)
{
/*	t_env	*envl;
	char	*exec = "ls";
	char	*path;// = "$USER$UfghSER$LESS";
	char	*argv[] = {"ls", "-l", NULL};

	envl = ft_setenvlist(env);
//	path = ft_expanstr(path, envl);
	path = ft_getenvval(envl, "PATH");
	path = ft_which(path, exec);
	execve(path, argv, env); */
	int ret = 1;
	char *line;
	while (ret)
	{
		ft_putstr ("GGG");
		if ((ret = get_next_line(0, &line)) == - 1)
			return (0);
	}
	return 0;
}
