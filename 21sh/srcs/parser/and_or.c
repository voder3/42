#include "libft.h"
#include "lexer.h"
#include "parser.h"

int	p_add_and_or(t_token *token, t_parser * parser)
{
	t_cmd_table	*table;
	t_and_or	*and_or;
	t_list		*new;

	(void)token;
	table = (t_cmd_table *)parser->curr_table->data;
	and_or = (t_and_or *)table->curr_and_or->data;
	and_or->type = token->type;
	if (!(new = ft_lstnew(NULL, 0))
	|| (!(new->data = init_and_or())))
		return (0);
	table->curr_and_or->next = new;
	table->curr_and_or = new;
	parser->state = 0;
	return (1);
}
