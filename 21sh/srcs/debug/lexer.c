#include "libft.h"
#include "ft_printf.h"
#include "lexer.h"

char	*escape_nl(char *src)
{
	char	*str;
	int	cnt;
	int	i;
	int	j;

	cnt = 0;
	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
	{
		if (src[i] == '\n')
			cnt++;
		i++;
	}
	i = 0;
	j = 0;
	str = ft_strnew(ft_strlen(src) + cnt);
	while (src[i])
	{
		if (src[i] == '\n')
		{
			str[j++] = '\\';
			str[j++] = 'n';
			i++;
		}
		else
			str[j++] = src[i++];
	}
	str[j] = '\0';
	return (str);
}

void	print_debug(t_list *elem)
{
	t_token *token = elem->data;
	char	*str;
	if (token->type == TOKEN)
		str = ft_strdup("TOKEN");
	if (token->type == WORD)
		str = ft_strdup("WORD");
	if (token->type == ASSIGNMENT_WORD)
		str = ft_strdup("ASSIGNMENT_WORD");
	if (token->type == NEWLINE)
	{
		ft_printf("str=%10.10s\ttype= %15s\n", "\\n", "NEWLINE");
		return ;
	}
	if (token->type == IO_NUMBER)
		str = ft_strdup("IO_NUMBER");
	if (token->type == AND_IF)
		str = ft_strdup("AND_IF");
	if (token->type == AMP)
		str = ft_strdup("AMP");
	if (token->type == OR_IF)
		str = ft_strdup("OR_IF");
	if (token->type == PIPE)
		str = ft_strdup("PIPE");
	if (token->type == SEMI)
		str = ft_strdup("SEMI");
	if (token->type == LESS)
		str = ft_strdup("LESS");
	if (token->type == DLESS)
		str = ft_strdup("DLESS");
	if (token->type == GREAT)
		str = ft_strdup("GREAT");
	if (token->type == DGREAT)
		str = ft_strdup("DGREAT");
	if (token->type == LESSAND)
		str = ft_strdup("LESSAND");
	if (token->type == GREATAND)
		str = ft_strdup("GREATAND");
	if (token->type == DLESSDASH)
		str = ft_strdup("DLESSDASH");
	ft_printf("str=%30s\ttype= %15s\t%p\n", escape_nl(token->str), str, token);
}

void	print_flag_queue(t_list *elem)
{
	t_lexer_flag	*flag;

	flag = (t_lexer_flag *)elem->data;
	ft_printf("%d\n", *flag);
}

char	*get_state_str(t_lexer *lexer)
{
	if (lexer->state == 0)
		return (ft_strdup("S_TK_START"));
	else if (lexer->state == 1)
		return (ft_strdup("S_HD_BODY"));
	else if (lexer->state == 2)
		return (ft_strdup("S_AMP_PIPE"));
	else if (lexer->state == 3)
		return (ft_strdup("S_TK_REDIR"));
	else if (lexer->state == 4)
		return (ft_strdup("S_EXP"));
	else if (lexer->state == 5)
		return (ft_strdup("S_TK_WORD"));
	else if (lexer->state == 6)
		return (ft_strdup("S_IO_NUMBER"));
	else if (lexer->state == 7)
		return (ft_strdup("S_FLAG"));
	return (NULL);
}
