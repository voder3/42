/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buil_jobs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:25:41 by artderva          #+#    #+#             */
/*   Updated: 2020/03/12 19:22:53 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"
#include "struct.h"

int     job_is_completed(t_job *job)
{
	t_list       *list;

	list = job->process;
	while (list)
	{
		if (((t_process*)(list->data))->status != COMPLETED)
			return (FAILURE);
		list = list->next;
	}
	return (SUCCESS);
}

int     job_is_stopped(t_job *job)
{
	t_list       *list;

	list = job->process;
	while (list)
	{
		if (((t_process *)(list->data))->status != STOPPED)
			return (FAILURE);
		list = list->next;
	}
	return (SUCCESS);
}

void	get_jstatus(t_job *job, char **stat)
{
	*stat = ft_strnew(32);

	if (job_is_completed(job) == SUCCESS)
		ft_strcpy(*stat, "Done");
	else if (job_is_stopped(job) == SUCCESS)
		ft_strcpy(*stat, "Suspended");
	else
		ft_strcpy(*stat, "Running");
}

int		print_jobs(t_list *list)
{
	t_job	*job;
	char	*state;

	state = NULL;
	while (list)
	{
		job = list->data;
		get_jstatus(job, &state);
		// recuperer job-number && current
		//		ft_printf("[%d]%c %.24s %s\n", job->number, job->current, 
		//				state, job->process->command);
		printf("[1] %.24s %s\n", state, job->cmd);
		ft_strdel(&state);
		list = list->next;
	}
	return (1);
}


int		ft_jobs(t_cfg *shell) //, t_process *process)
{
	int		opt;

	if (!(opt = ft_getopt(??, &, ,"")));
	print_jobs(shell->job);
	return (0);
}
