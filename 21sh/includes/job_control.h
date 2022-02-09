/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:11:27 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:11:27 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_CONTROL_H
# define JOB_CONTROL_H

void		one_process_change(t_process *p);
int32_t		job_has_finish(void *job, void *status);
void		add_job_cfg(t_job *job);
void		set_job_background(t_job *job);
void		ft_cpy_job(t_job *job, t_job *copy);
void		check_child(t_cfg *shell, t_list *lstjob);
void		aplylyse_wstatus(t_process *p, int wstatus);
void		update_process(t_list *lst, pid_t child, int wstatus);
t_process	*find_process_by_status(t_list *lst, uint8_t want);
t_process	*find_process_by_pid(t_list *lst, pid_t child);
void		update_listjob(t_cfg *shell);

#endif
