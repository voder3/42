/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:54:58 by artderva          #+#    #+#             */
/*   Updated: 2020/03/02 19:11:33 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <sys/param.h>
# include "ft_printf.h"
# include <stdarg.h>

typedef struct	s_msh
{
	int		lr;
	char	**input;
	char	*path; 
	char	**envp;
	t_list	*env_var;
}				t_msh;

typedef struct s_var
{
	char	*name;
	char	*value;
}				t_var;

typedef struct 	s_builtin
{
	char	*b;
	int		(*ft)(t_msh *msh);
}				t_builtin;

int				ft_setenvlist(t_list **list, char **envp);
char			*ft_getenv(t_list *env, char *name);

//char			*ft_expanstr(char *str, t_list *env);
//char			*ft_getenvval(t_env *env, char *str);
char			*ft_which(char *path, char *exec);
//char			**ft_unsetenvlist(t_env *env);
int				ft_is_exec(char *str, t_msh *msh);
char			**ft_exp_str(char **input, t_list *env);

int				ft_call_setenv(t_msh *msh);
int				ft_unsetenv(t_msh *msh);
int				ft_exit(t_msh *msh);
int				ft_echo(t_msh *msh);
int				ft_env(t_msh *msh);

int				find_builtin(char *str, t_msh *msh);

/****** env   ***/
//int		ft_env(t_msh *msh);
int		ft_call_setenv(t_msh *msh);
int		ft_setenv(t_list *lst, char *var, char *value, int overw);
int		ft_unsetenv(t_msh *msh);
t_list	*setenv_find(t_list *lst, char *name);
char	*ft_create_var_env(char **tab, int len0, int len1);
char	**ft_create_tab_env(t_list *lst, int count);


/*  cd   */

int				ft_call_cd(t_msh *msh);
int				ft_cd(char **str, t_msh *data);
char			cd_getopt(char **str, int *i);
int				cd_home(t_msh *msh);
char			*cd_setcurpath(t_msh *data, char *opr);
int				cd_logically(t_msh *data, char *curpath, char *opr);
int				cd_change_directory(t_msh *data, char *curpath, char *opr, char *pwd);

int				ft_isdir(char *path);
char			*ft_strrep(char *str, char *rem, char *rep);
char			*ft_pathjoin(char *s1, char *s2);

int				cd_set_relativepath(t_msh *data, char *curpath, char *opr, char *pwd);
char			*cd_del_dotcomponents(char *curpath, char *opr);
int				check_chdir_errors(char **str, char *path, char *opr);
int				check_whole_path(char *path);
int				display_cd_errors(char *error);


#endif
