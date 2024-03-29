/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:19 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:19 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "lexer.h"
#include "parser.h"
#include "var.h"
#include "line_edition.h"
#include "sh.h"

int		syn_err(t_token *token, t_parser *parser)
{
	ft_printf("syntax error near unexpected token `%s\' state=%d\n",
	token->str, parser->state);
	parser->state = S_PARSER_SYNTAX_ERROR;
	return (1);
}

int		p_skip(t_token *token, t_parser *parser)
{
	(void)token;
	(void)parser;
	return (1);
}

int		p_set_start_state(t_token *token, t_parser *parser)
{
	(void)token;
	parser->state = S_PARSER_TABLE_START;
	return (1);
}

char	*p_get_prompt_prefix(t_parser *parser)
{
	if (parser->pmt_prefix == AND_IF)
		return (ft_strdup("cmdand"));
	else if (parser->pmt_prefix == OR_IF)
		return (ft_strdup("cmdor"));
	else if (parser->pmt_prefix == PIPE)
		return (ft_strdup("pipe"));
	return (ft_strdup(""));
}
