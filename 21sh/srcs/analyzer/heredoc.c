/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:13 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:13 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "lexer.h"
#include "parser.h"
#include "analyzer.h"
#include "var.h"
#include "line_edition.h"
#include "sh.h"

static int		a_count_tabs(char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		if (*str == '\t')
			res++;
		str++;
	}
	return (res);
}

static void		a_tab_trim(t_redir *redir)
{
	char	*file;
	char	*res;
	int		i;

	if (redir->type != DLESSDASH)
		return ;
	i = 0;
	file = redir->file;
	if (!(res = ft_strnew(ft_strlen(file) - a_count_tabs(file))))
		ft_ex(EXMALLOC);
	while (*file)
	{
		while (*file && *file == '\t')
			file++;
		while (*file && *file != '\n')
		{
			res[i] = *file++;
			i++;
		}
		res[i] = *file++;
		i++;
	}
	ft_strdel(&redir->file);
	redir->file = res;
}

static void		a_trim_commands(t_and_or *and_or)
{
	t_list			*lst;
	t_simple_cmd	*cmd;
	t_list			*redir_lst;

	lst = and_or->s_cmd;
	while (lst)
	{
		cmd = lst->data;
		redir_lst = cmd->redir;
		while (redir_lst)
		{
			a_tab_trim(redir_lst->data);
			redir_lst = redir_lst->next;
		}
		lst = lst->next;
	}
}

void			a_remove_leading_tabs(t_cmd_table *table)
{
	t_list		*lst_and;

	lst_and = table->and_or;
	while (lst_and)
	{
		a_trim_commands(lst_and->data);
		lst_and = lst_and->next;
	}
}
