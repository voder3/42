/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:19 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:19 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"
#include "parser.h"
#include "ft_printf.h"

int		p_assign_val(t_token *token, t_parser *parser)
{
	t_cmd_table		*table;
	t_and_or		*and_or;
	t_simple_cmd	*cmd;
	t_assignment	*assign;

	table = (t_cmd_table *)parser->curr_table->data;
	and_or = (t_and_or *)table->curr_and_or->data;
	cmd = (t_simple_cmd *)and_or->curr_s_cmd->data;
	assign = (t_assignment *)cmd->curr_assign->data;
	if (token->str[0] && !(assign->val = ft_strdup(token->str + 1)))
		return (0);
	parser->state = S_PARSER_CMD_START;
	return (1);
}

int		p_add_assign(t_token *token, t_parser *parser)
{
	t_cmd_table		*table;
	t_and_or		*and_or;
	t_simple_cmd	*cmd;
	t_assignment	*assign;
	t_list			*new;

	(void)token;
	if (parser->state == S_PARSER_TABLE_START && !p_add_table(parser))
		return (0);
	table = (t_cmd_table *)parser->curr_table->data;
	and_or = (t_and_or *)table->curr_and_or->data;
	cmd = (t_simple_cmd *)and_or->curr_s_cmd->data;
	if (!(new = ft_lstnew(NULL, 0))
	|| !(assign = init_assignment()))
		return (0);
	new->data = assign;
	ft_lstaddtail(&cmd->assign, new);
	cmd->curr_assign = new;
	if (!(assign->var = ft_strdup(token->str)))
		return (0);
	parser->state = S_PARSER_ASSIGN;
	return (1);
}

int		p_assign_join(t_token *token, t_parser *parser)
{
	t_cmd_table		*table;
	t_and_or		*and_or;
	t_simple_cmd	*cmd;
	t_list			*lst;

	table = (t_cmd_table *)parser->curr_table->data;
	and_or = (t_and_or *)table->curr_and_or->data;
	cmd = (t_simple_cmd *)and_or->curr_s_cmd->data;
	lst = ft_lstgettail(cmd->args);
	if (!(lst->data = ft_strlclnjoin((char *)lst->data, token->str)))
		return (0);
	if (token->type == WORD)
		parser->state = S_PARSER_CMD_ARGS;
	return (1);
}
