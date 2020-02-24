#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "lexer.h"
#include "parser.h"
#include "line_edition.h"
#include "exec.h"
#include "sh.h"

void	print_debug(t_list *elem);

void	init_lexer(t_lexer *lexer)
{
	lexer->src = NULL;
	lexer->curr = NULL;
	lexer->state = S_TK_START;
	lexer->token_lst = NULL;
	lexer->curr_token = NULL;
	ft_bzero(lexer->buffer, L_BUFF_SIZE);
	lexer->buff_i = 0;
	lexer->flags = 0;
	lexer->here_queue = NULL;
	lexer->curr_here = NULL;
	lexer->flag_queue = NULL;
	lexer->curr_flag = NULL;
}

int		ft_lexer(char *str, t_lexer *lexer);

int		main(int ac, char **av, char **env)
{
	ssize_t		ret;
	char		*line;
	t_lexer		*lexer;
	t_parser	parser;
	t_dlist		*hist;

	(void)ac;
	(void)av;
	(void)env;
	t_cfg		shell;
	
	
	init_shell(&shell, env);
	(void)ac;
	(void)av;
	lexer = (t_lexer *)ft_memalloc(sizeof(t_lexer));
	ret = 0;
	hist = init_history();
	while ((line = ft_prompt("21sh-1.0$ ", &hist)))
	{
		if (ft_strequ("exit", line))
			exit(0);
		set_signal_ign();
		init_lexer(lexer);
		ft_lexer(line, lexer);
		ft_lstiter(lexer->token_lst, print_debug);
		ft_parser(lexer, &parser);
		ft_eval(&shell, parser.table);

		//ft_printf("$> ");
	}
	ft_dlstdel(&hist);
	return (0);
}

