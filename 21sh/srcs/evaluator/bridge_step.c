/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:14 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:14 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "exec.h"
#include "parser.h"
#include "analyzer.h"
#include "sh.h"

static uint8_t	condition_respected(t_and_or *andor, int8_t lr)
{
	if (andor->type == AND_IF)
		return (lr == SUCCESS ? 1 : 0);
	if (andor->type == OR_IF)
		return (lr == SUCCESS ? 0 : 1);
	return (FAILURE);
}

static uint8_t	lvl_simple_cmd(t_cfg *s, t_list *s_cmd, char *cmd, uint8_t fg)
{
	uint8_t		ret_job;
	t_job		job;

	cmd_to_job(s, &job, s_cmd, cmd);
	if ((job.fg = fg) && s->interactive)
		set_termios(TCSADRAIN, &job.term_eval);
	ret_job = run_job(s, &job, job.process);
	routine_clean_job(&job, sizeof(t_job));
	return (ret_job);
}

static uint8_t	lvl_and_or(t_cfg *shell, t_list *lst)
{
	uint8_t		ret_job;
	t_and_or	*andor;

	if (!lst)
		return (0);
	andor = lst->data;
	ret_job = lvl_simple_cmd(shell, andor->s_cmd, andor->str,
			!andor->background);
	if (lst->next && condition_respected(andor, ret_job))
		lvl_and_or(shell, lst->next);
	else if (lst->next)
		lvl_and_or(shell, lst->next->next);
	return (0);
}

static uint8_t	lvl_cmd_table(t_cfg *shell, t_list *lst)
{
	t_cmd_table		*cmd;

	while (lst)
	{
		cmd = lst->data;
		if (!analyzer_routine(cmd))
			return (FAILURE);
		lvl_and_or(shell, cmd->and_or);
		lst = lst->next;
	}
	return (SUCCESS);
}

uint8_t			ft_eval(t_list *cmd_table)
{
	t_cfg *shell;

	shell = cfg_shell();
	if (shell->debug)
		ft_dprintf(shell->debug, "\n\n--------- EVAL ----------\n\n");
	if (shell->interactive)
		set_signal_ign();
	if (lvl_cmd_table(shell, cmd_table))
		return (FAILURE);
	if (shell->debug)
		ft_dprintf(shell->debug, "---------- EVAL ----------\n\n");
	return (SUCCESS);
}
