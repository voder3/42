/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment.c                                          :+:      :+:    :+:   */
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

int			l_comment_line(t_lexer *lexer, char c)
{
	(void)c;
	lexer->state = S_COMMENT;
	return (1);
}

int			l_end_comment(t_lexer *lexer, char c)
{
	(void)c;
	lexer->state = S_TK_START;
	return (1);
}
