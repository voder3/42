/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:15 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:15 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "exec.h"

t_process	*find_process_by_pid(t_list *lst, pid_t child)
{
	t_process *p;

	while (lst)
	{
		p = lst->data;
		if (p->pid == child)
			return (p);
		lst = lst->next;
	}
	return (NULL);
}

t_process	*find_process_by_status(t_list *lst, uint8_t want)
{
	t_process *p;

	while (lst)
	{
		p = lst->data;
		if (p->status & want)
			return (p);
		lst = lst->next;
	}
	return (NULL);
}

uint8_t		builtin_process(t_job *j, t_process *p)
{
	uint8_t		(*tab_f[11])(t_job *, t_process *);

	tab_f[0] = ft_echo;
	tab_f[1] = ft_cd;
	tab_f[2] = ft_env;
	tab_f[3] = ft_setenv;
	tab_f[4] = ft_unsetenv;
	tab_f[5] = ft_hash;
	tab_f[6] = ft_exit;
	tab_f[7] = ft_jobs;
	tab_f[8] = ft_fg;
	tab_f[9] = ft_bg;
	tab_f[10] = ft_type;
	if (p->status == FAILED)
		return (p->ret);
	if ((p->ret = tab_f[(p->setup >> 14)](j, p)))
		p->status = FAILED;
	else
		p->status = COMPLETED;
	return (p->ret);
}

void		process_type(t_process *p)
{
	uint32_t	err;

	err = 0;
	if (ft_strchr(p->cmd, '/'))
		with_slash(p, &err);
	else
		(any_slash(p->env, p, &err));
	if (err && (p->setup & R_ERROR))
		p->setup |= P_ERROR;
	else if (err)
		p->setup |= process_errors_handling(p, err);
}
