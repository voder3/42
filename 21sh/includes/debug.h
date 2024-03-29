/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:11:27 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:11:27 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

int		get_nb_cmd(t_list *cmd);
int		get_nb_and_or(t_list *and_or);
int		get_nb_word_list(t_list *list);
char	*get_redir_op(t_token_type type);
char	*get_and_or_type_str(t_and_or *and_or);
void	print_s_cmd(t_list *cmd_list);
void	print_line(void);
char	*escape_nl(char *src);
void	print_flag_queue(t_list *elem);
char	*get_flag_name(t_lexer_flag flag);
char	*get_state_str(t_lexer *lexer);
void	print_assignment(t_list *assignment);
void	print_redir(t_list *redirection);

#endif
