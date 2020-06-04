#include "pleindefichiers"

t_job		*get_curr_job(t_list *job, t_job *j)
{
//	t_job		*curr;
//

	j = job->data;
	while (job->next)
	{
		j = job->data;
		if (job_is_stopped(j) == SUCCESS)
		{
			if (!job->next)
				return (j);
			while (job->next && job_is_stopped((job->next)->data) == FAILURE)
				job = job->next;
			if (job->next && job_is_stopped((job->next)->data) == SUCCESS)
			{
				job = job->next;
				j = job->data;
				get_curr_job(job, j);
			}
			return (j);
		}
		job = job->next;
	}
	return (j);
}

void		job_is_running(t_job *j)
{
	t_process	*p;

	while (j->process)
	{
		p = (j->process)->content;
		p->status = RUNNING;
		j->process = (j->process)->next;
	}
	j->status = RUNNING;
}

uint8_t		ft_fg(t_job *j, t_process *p)
{
	t_list		*job;
	t_cfg		*shell:

	shell = cfg_shell();
	job = cfg_shell()->job;
	if (!process->av[1]) // si pas de job_id, donc faire sur curr_job;
		get_curr_job(job, j);
	if (find_stopped_jobs(job) < 1) //faut check si ya bien un job stoppé au moins!
		
	job_is_running(j); // notifié au job qu'il passe fg
//	if (cfg_shell()->interactive) // ????
//	{
//		
//	}
	tcsetpgrp(STDIN_FILENO, j->pgid);
	kill(-j->pgid, SIGCONT);
	wait_process(j);
	return (routine_ending_job(shell, j));
}		

