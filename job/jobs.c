#include "libft.h"
#include "exec.h"
#include "struct.h"
#include "sh.h"
#include "var.h"
#include "ft_printf.h"

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



uint8_t 	ft_jobs(t_job *j, t_process *p)
{
	t_list 	*job;
	char	*state;

	job = cfg_shell()->job;
	while (job)
	{
		j = job->data;
		get_jstatus(j, &state);
		ft_printf("[%d] %-24s %s\n", j->id, state, j->cmd);
		ft_strdel(&state);
		job = job->next;
	}
	(void)p;
	return (0);
}
