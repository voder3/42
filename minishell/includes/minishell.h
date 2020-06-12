/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:54:58 by artderva          #+#    #+#             */
/*   Updated: 2020/06/12 18:11:24 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <sys/param.h>
# include <stdarg.h>
# include <inttypes.h>
# include <stdint.h>

typedef struct		s_msh
{
	char			**input;
	t_list			*env_var;
}					t_msh;

typedef struct		s_var
{
	char			*tab[2];
}					t_var;

int					ft_setenvlist(t_list **list, char **envp);
char				*ft_getenv(t_list *env, char *name);
char				*ft_which(char *path, char *exec);
int					ft_is_exec(t_msh *msh);
char				**ft_exp_str(char **input, t_list *env);
int					ft_call_setenv(t_msh *msh);
int					ft_unsetenv(t_msh *msh);
int					ft_setenv(t_msh *msh);
int					ft_exit(t_msh *msh);
int					ft_echo(t_msh *msh);
int					ft_env(t_msh *msh);
int					ft_call_cd(t_msh *msh);
int					find_builtin(t_msh *msh);
int					ft_error(char *s1, char *s2);
void				ft_ex(char *s1, char *s2);
char				*ft_getenvval(t_list *env, char *str, int free);
char				*ft_dolls(char *str, t_list *env, int *len);

int					ft_cd(char **str, t_msh *data);
char				cd_getopt(char **str, int *i);
int					cd_home(t_msh *msh);
char				*cd_setcurpath(t_msh *data, char *opr);
int					cd_logically(t_msh *data, char *curpath, char *opr);
int					cd_change_directory(t_msh *d, char *cp, char *o, char *pw);

char				*ft_strrep(char *str, char *rem, char *rep);
char				*ft_pathjoin(char *s1, char *s2);
int					cd_update_pwd(t_msh *data, char *pwd, char *oldpwd);

int					cd_set_relativepath(t_msh *d, char *c, char *o, char *pwd);
char				*cd_del_dotcomponents(char *curpath, char *opr);
int					check_chdir_errors(char **str, char *path, char *opr);
int					check_whole_path(char *path);
int					display_cd_errors(char *error);

void				free_struct(t_msh *data);
void				del_struct_tvar(void *del, size_t u);
int					ft_isdir(char *path);
int					is_file(char *path, char *str);

#endif
