/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:28:02 by artderva          #+#    #+#             */
/*   Updated: 2020/03/12 19:00:57 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "struct.h"

char	**cpy_arr(char	**arr)
{
	char	**ret;
	int i;

	i = 0;
	while (arr[i])
		i++;
	if (!(ret = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (arr[i])
	{
		if (!(ret[i] = ft_strdup(arr[i])))
			return (NULL);
		i++;
	}
	return (ret);
}

uint8_t		cpy_lst_env(t_var *env, t_var *copy)
{
	if (!(copy->ctab = cpy_arr(env->ctab)))
		return (FAILURE);
	copy->rd = env->rd;
	return (SUCCESS);
}

uint8_t		cpy_lst_process(t_process *proc, t_process *copy)
{
	ft_memcpy(copy, process, sizeof(t_process));
	if (!(copy->cmd = ft_strdup(process->cmd)))
		return (FAILURE);
	if (!(copy->av = cpy_arr(process->ar)))
		return (FAILURE);
	if (!(copy->path = ft_strdup(process->path)))
		return (FAILURE);
	copy->std[0] = process->std[0];
	copy->std[1] = process->std[1];
	copy->std[2] = process->std[2];
	return (SUCCESS);
}

uint8_t		cpy_tpipe(t_pipe *pipe, t_pipe *copy)
{
	copy->fd[0] = pipe->fd[0];
	copy->fd[1] = pipe->fd[1];
	copy->tmp = pipe->tmp;
}

uint8_t		cpy_job(t_job *job)
{
	t_job	*copy;

	if (!(copy = (t_job *)malloc(sizeof(t_job) + 1)))
		return (FAILURE);
	if (!(copy->command = ft_strdup(job->command)))
		return (FAILURE);
//	if (!(copy->process) = malloc(sizeof(t_list)))
//		return (FAILURE);
	if (!(copy->process = ft_lstdup(job->process, job->process->size,
		cpy_lst_process(((t_process*)(job->process)->data),((t_process *)(copy->process)->data))))) // ??i
		return (FAILURE);
	if (!(copy->env = ft_lstdup(job->env, job->env->size,
		cpy_lst_env(((t_var*)(job->env)->data),(t_var*)(copy->env)->data))))
		return (FAILURE);
	copy->pgid = job->pgid;
	copy->fg = job->fg;
	cpy_tpipe(job->pipe, copy->pipe);
	copy->status = job->status;
	copy->ret = job->ret;
	copy->std[0] = job->std[0];
	copy->std[1] = job->std[1];
	copy->std[2] = job->std[2];
	if (!(copy->termios = malloc(sizeof(struct termios))))
		return (FAILURE);
	ft_memcpy(&copy->termios, &job->termios, sizeof(struct termios));
}
