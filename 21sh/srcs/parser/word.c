/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:20 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:20 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"
#include "parser.h"

int	p_cmd_name(t_token *token, t_parser *parser)
{
	t_cmd_table		*table;
	t_and_or		*and_or;
	t_simple_cmd	*cmd;

	if (parser->state == S_PARSER_TABLE_START && !p_add_table(parser))
		return (0);
	table = (t_cmd_table *)parser->curr_table->data;
	and_or = (t_and_or *)table->curr_and_or->data;
	cmd = (t_simple_cmd *)and_or->curr_s_cmd->data;
	if (!(cmd->cmd_name = ft_strdup(token->str)))
		return (0);
	parser->state = S_PARSER_CMD_ARGS;
	return (1);
}

int	p_add_arg(t_token *token, t_parser *parser)
{
	t_cmd_table		*table;
	t_and_or		*and_or;
	t_simple_cmd	*cmd;
	char			*str;

	table = (t_cmd_table *)parser->curr_table->data;
	and_or = (t_and_or *)table->curr_and_or->data;
	cmd = (t_simple_cmd *)and_or->curr_s_cmd->data;
	if (!(str = ft_strdup(token->str))
	|| !ft_lstpush(&cmd->args, str, sizeof(char *)))
		return (0);
	return (1);
}

int	p_add_assign_arg(t_token *token, t_parser *parser)
{
	if (!p_add_arg(token, parser))
		return (0);
	parser->state = S_PARSER_ARG_ASSIGN;
	return (1);
}

int	p_file_name(t_token *token, t_parser *parser)
{
	t_cmd_table		*table;
	t_and_or		*and_or;
	t_simple_cmd	*cmd;
	t_redir			*redir;

	table = (t_cmd_table *)parser->curr_table->data;
	and_or = (t_and_or *)table->curr_and_or->data;
	cmd = (t_simple_cmd *)and_or->curr_s_cmd->data;
	redir = (t_redir *)cmd->curr_redir->data;
	if ((redir->type == GREATAND || redir->type == LESSAND)
	&& !ft_strequ(token->str, "-") && !is_digitstr(token->str))
		syn_err(token, parser);
	if (!(redir->file = ft_strdup(token->str)))
		return (0);
	if (parser->prev_state == S_PARSER_ANDIF_PIPE
	|| parser->prev_state == S_PARSER_TABLE_START)
		parser->state = S_PARSER_CMD_START;
	else
		parser->state = parser->prev_state;
	return (1);
}
