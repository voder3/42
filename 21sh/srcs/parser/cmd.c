/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
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

int	p_add_cmd(t_token *token, t_parser *parser)
{
	t_cmd_table		*table;
	t_and_or		*and_or;
	t_simple_cmd	*cmd;

	(void)token;
	table = (t_cmd_table *)parser->curr_table->data;
	and_or = (t_and_or *)table->curr_and_or->data;
	if (!(cmd = init_simple_cmd())
	|| !ft_lstpush(&and_or->s_cmd, cmd, sizeof(t_simple_cmd)))
		return (0);
	and_or->curr_s_cmd = and_or->curr_s_cmd->next;
	parser->state = S_PARSER_ANDIF_PIPE;
	parser->pmt_prefix = token->type;
	return (1);
}
