/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:14 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:14 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh.h"
#include "exec.h"
#include <unistd.h>

void	del_struct_tvar(void *del, size_t u)
{
	t_var	*v;

	(void)u;
	v = del;
	ft_del_tab((void **)v->ctab);
	free(v);
}

void	clean_cfg(t_cfg *shell)
{
	ft_lstdel(&shell->env, del_struct_tvar);
	ft_lstdel(&shell->intern, del_struct_tvar);
	ft_lstdel(&shell->sp, del_struct_tvar);
	ft_lstdel(&shell->job, del_struct_job);
	ft_dlstdel(&shell->history);
	ft_hash_del_map(&shell->map, free);
	ft_hash_del_map(&shell->input_map, NULL);
	ft_strdel(&shell->file);
	ft_bzero(shell, sizeof(t_cfg));
}
