#include "exec.h"
//#include ""

int	shell_is_interactive()
{
	
	int	shell;

	shell = STDIN_FILENO;
	if (isatty(shell))
		return (SUCCES);
	return (FAILURE);
}

void	put_job_in_foreground(t_job *j, int cont)
{
	tcsetpgrp(STDIN_FILENO, job->pgid);

	if (cont)
	{
		tcsetattr(STDIN_FILENO, TCSADRAIN, job->tmodes);
		if (kill(-job->pgid, SIGCONT) < 0)
			perror sa mere; KILL SIGCONT;
	}
	wait_for_job(job);
	tcsetpgrp(STDIN_FILENO, job->pgid); // shell back in foreground

	tcgetattr(STDIN_FILENO, job->tmodes); // restore shell tterm mode
	tcsetattr(STDIN_FILENO, )// ??? 

}

void	put_job_in_bakground(t_job *j, int cont)
{
	if (cont)
	{
		if (kill (-job->pgid, SIGCONT) < 0)
			//perror
	}
}

int		save_job(t_job *job, t_job *new)
{
//	t_job	*new;

	if (!job || !new)
		return (FAILURE);
	if (!(new->command = ft_strdup(job->command)))
		return (FAILURE);
	if (!(new->process = ft_lstcpy(job->process)))
		return (FAILURE);
	if (!(new->var = ft_lstcpy(job->var)))
		return (FAILURE);
	new->pgid = job->pgid;
	new->fg = job->fg;
	pipppe;
	new->notified = job->notified;


}
