/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:15 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:15 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh.h"
#include "exec.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int32_t		create_fd_null(void)
{
	int32_t	fd;

	if ((fd = open("/dev/null", 0)) == -1)
		if ((fd = open("/tmp/tmpfd2142sh", O_CREAT, 0644)) == -1)
			return (0);
	return (fd);
}

uint8_t		bad_fd(int fd)
{
	struct stat buf;

	if (fstat(fd, &buf) == FALSE)
		return (FAILURE);
	return (SUCCESS);
}

uint32_t	right_fifo(char *path, uint32_t *right)
{
	struct stat buf;

	lstat(path, &buf);
	ft_bzero(&buf, sizeof(struct stat));
	if (!S_ISFIFO(buf.st_mode))
		return (0);
	if (access(path, R_OK | W_OK) != SUCCESS)
		return (E_ACCES);
	*right = O_RDWR;
	return (SUCCESS);
}

void		builtin_save_fd(t_job *j)
{
	uint8_t		i;
	int16_t		fd[3];

	i = 0;
	fd[0] = SAVE_IN;
	fd[1] = SAVE_OUT;
	fd[2] = SAVE_ERR;
	while (i < 3)
	{
		if (!bad_fd(i))
		{
			j->std[i] = fd[i];
			do_my_dup2(i, j->std[i]);
		}
		else
			j->std[i] = -1;
		i++;
	}
}

void		builtin_restor_fd(t_job *j)
{
	uint8_t		i;
	int16_t		fd[3];

	i = 0;
	fd[0] = SAVE_IN;
	fd[1] = SAVE_OUT;
	fd[2] = SAVE_ERR;
	while (i < 3)
	{
		if (j->std[i] == -1)
			close(i);
		else
		{
			do_my_dup2(j->std[i], i);
			close(j->std[i]);
		}
		i++;
	}
}
