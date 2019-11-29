/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:54:58 by artderva          #+#    #+#             */
/*   Updated: 2019/11/29 04:20:08 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <sys/param.h>

typedef struct	s_env
{
       char                    *name;
       char                    *value;
       struct s_env    *next;
}				t_env;

typedef struct	s_msh
{
	int		lr;
	char	**input;
	char	*path;
	char	**env;
	t_env	*envl;
}				t_msh;

t_env			*ft_setenvlist(char **env);
char			*ft_getenv(t_env *env, char *name);

char			*ft_expanstr(char *str, t_env *env);
char			*ft_getenvval(t_env *env, char *str);
char			*ft_which(char *path, char *exec);
char			**ft_unsetenvlist(t_env *env);
int				ft_is_exec(char *str, t_msh *msh);
char			**ft_exp_str(char **input, t_env *env);

int				ft_setenv(t_msh *msh);
int				ft_unsetenv(t_msh *msh);
int				ft_exit(t_msh *msh);
int				ft_echo(t_msh *msh);
int				ft_env(t_msh *msh);

int				find_builtin(char *str, t_msh *msh);
#endif
