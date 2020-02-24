/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:41:12 by artderva          #+#    #+#             */
/*   Updated: 2019/07/16 17:01:37 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file	*getf(t_file **f_list, int fd)
{
	t_file	*file;

	file = NULL;
	if (f_list && *f_list)
		file = *f_list;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	if (!(file = ft_memalloc(sizeof(t_file))))
		return (NULL);
	file->cont = ft_strnew(0);
	file->fd = fd;
	file->next = *f_list;
	*f_list = file;
	return (file);
}

static char		*ft_sdup(char *str, size_t len)
{
	char	*tmp;

	if (!(tmp = ft_strdup(str + len + 1)))
		return (NULL);
	ft_strdel(&str);
	return (tmp);
}

static	int		ft_free(t_file **file, int fd)
{
	t_file	*prev;

	if ((*file)->fd == fd)
	{
		ft_strdel(&((*file)->cont));
		prev = (*file)->next;
		free(*file);
		*file = prev;
	}
	else
	{
		while ((*file)->next)
		{
			prev = *file;
			*file = (*file)->next;
			if ((*file)->fd == fd)
			{
				ft_strdel(&((*file)->cont));
				prev->next = (*file)->next;
				free(*file);
			}
		}
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	size_t			len;
	char			buf[BUFF_SIZE + 1];
	static t_file	*f_list;
	t_file			*file;
	ssize_t			ret;

	if (!line || fd < 0 || read(fd, buf, 0) < 0 || !(file = getf(&f_list, fd)))
		return (-1);
	ret = 0;
	while (!ft_strchr(file->cont, 10) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(file->cont = ft_sjoin(file->cont, buf)))
			return (-1);
	}
	len = 0;
	while (file->cont[len] != 10 && file->cont[len])
		len++;
	*line = ft_strsub(file->cont, 0, len);
	if (ret == 0 && !*(file->cont))
		return (ft_free(&f_list, fd));
	ft_strlen(file->cont) > len ? file->cont = ft_sdup(file->cont, len) :
	ft_strclr(file->cont);
	return (file->cont ? 1 : -1);
}
