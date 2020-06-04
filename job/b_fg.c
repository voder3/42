/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:22:57 by artderva          #+#    #+#             */
/*   Updated: 2020/03/12 19:24:41 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "struct.h"

int8_t	check_jobid(char *s)
{
	int8_t	ret;

	if (ft_is_digit(s + 1))
		return (ft_atoi(s + 1));
	else if ((!(ft_strcmp(s, "%%"))) || (!(ft_strcmp(s, "%+"))))
	{
		//renvoie le pgid de cur_job ou job_number balek!!
	}
	else if (!(ft_strcmp(s, "%-")))
	{
		// return le pgid de prev_job si yen a sinon e cur_job
	}
	else if (s[1] == '?')
	{
		//chercher si ya 1 seul job avec la string apres le ?
	}
	else
	{
		// chercher si 1 seul job commence par str
	}
}

// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap03.html#tag_03_204
// tableau des difs job id
// getjobid renvoie un tablaeu -> job number? ou jid, -1 si ca correcpond a 

int8_t	*getjobid(char **av)//, int ac)
{
	int8_t	*jid;
	uint8_t	size;
	uint8_t	i;
	int8_t	j;

	// obtenir la position du premier jid, avec size ou ac???
	// i doit etre sur le premier jid
	i = 1;
	while (av[i][0] == '-')
		i++;
	j = i;
	while (av[j][0] == '%')
		j++;
	if (!(jid = malloc(sizeof(uint8_t) * (j - i + 2))))//size)))
		return (NULL);
	j = 0;
	while (av[i][0] == '%')
	{
		jid[j] = check_jobid(av[i]);
	}
}


// ex : jobs %- %2 %2 %68 %3
uint8_t		b_fg(t_cfg *shell, t_process *process)
{
	int8_t	**ope;

	if (!(ope = getjobid(process->av)))//, 1))) // 1 a rempl, savoir le nbr de job? -> checkjid
		return (FAILURE);
	
}
