/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:16 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:16 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "lexer.h"

t_lexer_flag		l_get_last_flag(t_lexer *lexer)
{
	t_list		*flag;

	flag = ft_lstgettail(lexer->flag_queue);
	if (flag && flag->data)
		return (*((t_lexer_flag *)flag->data));
	return (0);
}

int					l_add_flag(t_lexer *lexer, char c)
{
	if (!(l_create_flag_queue(lexer)))
		return (0);
	if (c == '\'')
		*lexer->curr_flag = F_SQUOTE;
	else if (c == '\"')
		*lexer->curr_flag = F_DQUOTE;
	else if (c == '{')
		*lexer->curr_flag = F_BRACKEXP;
	else if (c == '\\')
		*lexer->curr_flag = F_BSLASH;
	return (1);
}

static void			l_flag_handle_dquote(t_lexer *lexer, char c)
{
	if (c == '$')
		l_build_exp(lexer, c);
	else if (c == '\\')
		l_bslash_add(lexer, c);
	else
		l_buffer_add(lexer, c);
}

int					l_flag_state_add(t_lexer *lexer, char c)
{
	t_lexer_flag	flag;

	flag = l_get_last_flag(lexer);
	if (flag == F_BSLASH || (flag == F_BRACKEXP && c == '}'))
	{
		l_buffer_add(lexer, c);
		ft_lstdeltail(&lexer->flag_queue, del_flag_queue);
		if (!l_get_last_flag(lexer))
			lexer->state = S_TK_WORD;
		if (c == '\n')
			return (l_complete_str(lexer, l_get_char(lexer)));
	}
	else if (flag == F_DQUOTE)
		l_flag_handle_dquote(lexer, c);
	else if ((flag == F_BRACKEXP && c == '}'))
	{
		l_buffer_add(lexer, c);
		lexer->state = S_TK_WORD;
		ft_lstdeltail(&lexer->flag_queue, del_flag_queue);
	}
	else if ((flag == F_BRACKEXP && c == '$'))
		l_build_exp(lexer, c);
	else
		l_buffer_add(lexer, c);
	return (1);
}

int					l_delim_flag(t_lexer *lexer, char c)
{
	t_lexer_flag	flag;

	flag = l_get_last_flag(lexer);
	if (flag == F_BSLASH)
		ft_lstdeltail(&lexer->flag_queue, del_flag_queue);
	else if (c == '\'' && flag == F_SQUOTE)
		ft_lstdeltail(&lexer->flag_queue, del_flag_queue);
	else if (c == '\'' && flag != F_DQUOTE)
		l_add_flag(lexer, c);
	else if (c == '\"' && flag == F_DQUOTE)
		ft_lstdeltail(&lexer->flag_queue, del_flag_queue);
	else if (c == '\\' && flag != F_SQUOTE)
		l_add_flag(lexer, c);
	else if (c == '}' && flag == F_BRACKEXP)
		ft_lstdeltail(&lexer->flag_queue, del_flag_queue);
	else if (c == '\"' && flag == F_BRACKEXP)
		l_add_flag(lexer, c);
	l_buffer_add(lexer, c);
	if (!l_get_last_flag(lexer))
		lexer->state = S_TK_WORD;
	return (1);
}
