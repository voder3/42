/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:20 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:20 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	p_init_io_nbr_state(
		int (*table_builder[10][17])(t_token *, t_parser *))
{
	table_builder[S_PARSER_IO_NUMBER][TOKEN] = syn_err;
	table_builder[S_PARSER_IO_NUMBER][WORD] = syn_err;
	table_builder[S_PARSER_IO_NUMBER][ASSIGNMENT_WORD] = syn_err;
	table_builder[S_PARSER_IO_NUMBER][NEWLINE] = syn_err;
	table_builder[S_PARSER_IO_NUMBER][IO_NUMBER] = syn_err;
	table_builder[S_PARSER_IO_NUMBER][AND_IF] = syn_err;
	table_builder[S_PARSER_IO_NUMBER][AMP] = syn_err;
	table_builder[S_PARSER_IO_NUMBER][OR_IF] = syn_err;
	table_builder[S_PARSER_IO_NUMBER][PIPE] = syn_err;
	table_builder[S_PARSER_IO_NUMBER][SEMI] = syn_err;
	table_builder[S_PARSER_IO_NUMBER][LESS] = p_add_redir;
	table_builder[S_PARSER_IO_NUMBER][DLESS] = p_add_redir;
	table_builder[S_PARSER_IO_NUMBER][GREAT] = p_add_redir;
	table_builder[S_PARSER_IO_NUMBER][DGREAT] = p_add_redir;
	table_builder[S_PARSER_IO_NUMBER][LESSAND] = p_add_redir;
	table_builder[S_PARSER_IO_NUMBER][GREATAND] = p_add_redir;
	table_builder[S_PARSER_IO_NUMBER][DLESSDASH] = p_add_redir;
}
