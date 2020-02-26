#include "parser.h"
#include "exec.h"

// https://www.gnu.org/software/libc/manual/html_node/Stopped-and-Terminated-Jobs.html#Stopped-and-Terminated-Jobs


int	job_is_completed(t_job *job)
{
	t_process	*process;

	process = job->process;
	while (process)
	{
		if (process->completed == FALSE)
			return (FAILURE);
		process = process->next;
	}
	return (SUCCES);
}

int	job_is_stopped(t_job *job)
{
	t_process	*process;

	process = job->process;
	while (process)
	{
		if (process->stopped == FALSE)
			return (FAILURE);
		process = process->next;
	}
	return (SUCCES);
}

int	mark_process_status(pid_t pid, int status)
{
	t_job		*job;
	t_list		*process;

	if (pid > 0)
	{
		// job = ??? variable globale a set
		while (job)
		{
			process = job->process;
			while (process)
			{
				if (((t_process*)process->data)->pid == pid)
				{
					((t_process*)process->data)->status = status;
					if (WIFSTOPPED(status))
						((t_process*)process->data)->stopped = 1;
					else
					{
						((t_process*)process->data)->completed = 1;
						if (WIFSIGNALED(status))
						{
							ft_dprintf(2,  "%d: Terminated by signal %d.\n", pid, WTERMSIG (t_process*(process->data)->status));

						}
						return (SUCCES);
					}
					ft_dprintf(2, "No child process %d.\n", pid);
					return (FAILURE);
				}
			}
		}
	}
	else if (pid = 0 )// ? | errno = ECHILD ??
		return (FAILURE);
	else
	{
		perror("waitpid");
		return (FAILURE);
	}

}



void	wait_for_job(t_job *job)
{
	int	status;
	pid_t	pid;

	pid = waitpid(WAIT_ANY, &status, WUNTRACED);
	while (!mark_process_status(pid, status) && !job_is_stopped(job) && !job_is_completed(job))
	{
		// ?
	}

}
