/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:20 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:20 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	p_init_syn_err_state(
		int (*table_builder[10][17])(t_token *, t_parser *))
{
	table_builder[S_PARSER_SYNTAX_ERROR][TOKEN] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][WORD] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][ASSIGNMENT_WORD] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][NEWLINE] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][IO_NUMBER] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][AND_IF] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][AMP] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][OR_IF] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][PIPE] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][SEMI] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][LESS] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][DLESS] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][GREAT] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][DGREAT] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][LESSAND] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][GREATAND] = p_skip;
	table_builder[S_PARSER_SYNTAX_ERROR][DLESSDASH] = p_skip;
}
