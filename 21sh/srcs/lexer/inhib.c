/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inhib.c                                            :+:      :+:    :+:   */
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

int	l_build_inhib(t_lexer *lexer, char c)
{
	if (lexer->state == S_TK_START)
	{
		if (!l_create_token(lexer))
			return (0);
	}
	if (ft_strchr("\"\'\\", c))
		l_add_flag(lexer, c);
	l_buffer_add(lexer, c);
	lexer->state = S_FLAG;
	lexer->curr_token->type = WORD;
	return (1);
}

int	l_delim_inhib(t_lexer *lexer, char c)
{
	l_delim_token(lexer, c);
	lexer->state = S_TK_START;
	if (!l_build_inhib(lexer, c))
		return (0);
	return (1);
}
