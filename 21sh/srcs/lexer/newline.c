#include "libft.h"
#include "ft_printf.h"
#include "lexer.h"

int	l_build_newline(t_lexer *lexer, char c)
{
	if (l_get_flag(lexer, F_HEREDOC))
	{
		lexer->state = S_HD_BODY;
		lexer->curr_here = lexer->here_queue->data;
		lexer->curr_token = lexer->curr_here->token;
		//ft_printf("coucou token %p dans here %p\n", lexer->curr_here->token, lexer->curr_here);
		return (1);
	}
	else if (!l_create_token(lexer))
		return (0);
	l_buffer_add(lexer, c);
	lexer->curr_token->type = NEWLINE;
	l_buffer_flush(lexer);
	return (1);
}

int	l_delim_newline(t_lexer *lexer, char c)
{
	l_delim_token(lexer, c);
	l_build_newline(lexer, c);
	return (1);
}
