#include "libft.h"
#include "lexer.h"
#include "parser.h"
#include "ft_printf.h"

int		p_assign_val(t_token *token, t_parser *parser)
{
	t_cmd_table	*table;
	t_and_or	*and_or;
	t_simple_cmd	*cmd;
	t_assignment	*assign;

	table = (t_cmd_table *)parser->curr_table->data;
	and_or = (t_and_or *)table->curr_and_or->data;
	cmd = (t_simple_cmd *)and_or->curr_s_cmd->data;
	assign = (t_assignment *)cmd->curr_assign->data;
	if (token->str[0] && !(assign->val = ft_strdup(token->str + 1)))
		return (0);
	parser->state = 1;
	return (1);
}

int		p_add_assign(t_token *token, t_parser *parser)
{
	t_cmd_table	*table;
	t_and_or	*and_or;
	t_simple_cmd	*cmd;
	t_assignment	*assign;
	t_list		*new;

	(void)token;
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
	parser->state = 4;
	return (1);
}
