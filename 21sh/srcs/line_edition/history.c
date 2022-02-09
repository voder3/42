/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:18 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:18 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "sh.h"
#include "get_next_line.h"
#include "var.h"
#include "line_edition.h"
#include "struct.h"
#include <stdlib.h>

int			ft_strcheck(char *s, char *oc)
{
	int	i;

	if (s && oc)
	{
		i = 0;
		while (s[i])
			if (!ft_strchr(oc, s[i++]) && s[i - 1] != '\n')
				return (0);
		return (1);
	}
	return (0);
}

static char	*get_home(void)
{
	t_cfg	*cfg;
	char	*home;

	if ((cfg = cfg_shell()))
		if ((home = find_var_value(cfg->env, "HOME")))
			return (home);
	return (".");
}

static void	history_updater(t_cs_line *cs, t_dlist *hs, int fd)
{
	int	len;

	len = ft_strlen(cs->input);
	if (!(hs->prev && hs->prev->data && (cs->input[len - 1] = '\0')
		== 0 && ft_strcmp(cs->input, (char *)hs->prev->data) == 0))
	{
		ft_strdel((char **)&hs->data);
		hs->data = (void *)ft_strdup(cs->input);
		cs->input[len - 1] = '\n';
		ft_putstr_fd(cs->input, fd);
	}
	else
		ft_dlstdelone(&hs);
}

void		update_history(t_dlist *hs)
{
	int			fd;
	char		*path;
	t_cs_line	*cs;

	cs = cs_master(NULL, 0);
	if (hs && cs && cs->history)
	{
		ft_asprintf(&path, "%s/.%s_history", get_home(), PROJECT);
		cs->history->data = (void *)cs->old_history;
		while (hs && hs->next)
			hs = hs->next;
		if (hs && cs && path && cs->input && cs->input[0] && cs->input[0]
			!= '\n' && (fd = open(path, O_CREAT | O_APPEND | O_WRONLY, 0666)))
		{
			history_updater(cs, hs, fd);
			ft_strdel(&cs->input);
			close(fd);
		}
		ft_strdel(&path);
	}
}

t_dlist		*get_history(void)
{
	t_dlist	*hs;
	char	*line;
	int		fd;

	if ((hs = ft_dlstnew(NULL, 0)))
	{
		ft_asprintf(&line, "%s/.%s_history", get_home(), PROJECT);
		if ((fd = open(line, O_RDONLY)) > 0)
		{
			ft_strdel(&line);
			while (get_next_line(fd, &line) > 0)
				ft_dlstaddtail(&hs, ft_dlstnew(line, 1));
			close(fd);
		}
		else
			ft_strdel(&line);
	}
	return (hs);
}
