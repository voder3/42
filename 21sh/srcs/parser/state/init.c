/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:20 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:20 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "lexer.h"
#include "parser.h"
#include "var.h"
#include "line_edition.h"
#include "sh.h"

void	p_init_state_machine(
		int (*table_builder[10][17])(t_token *, t_parser *))
{
	p_init_start_state(table_builder);
	p_init_cmd_wait_state(table_builder);
	p_init_args_wait_state(table_builder);
	p_init_redir_state(table_builder);
	p_init_assign_state(table_builder);
	p_init_io_nbr_state(table_builder);
	p_init_delim_state(table_builder);
	p_init_assign_state(table_builder);
	p_init_arg_assign_state(table_builder);
	p_init_andif_pipe_state(table_builder);
	p_init_syn_err_state(table_builder);
}
