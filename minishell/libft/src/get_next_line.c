/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <artderva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:20 by artderva          #+#    #+#             */
/*   Updated: 2020/06/04 18:42:25 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_cut_str(char *str, size_t i)
{
	char *ret;

	if (!(ret = ft_strnew(ft_strlen(str) - i)) || !str)
		return (NULL);
	if (i < ft_strlen(str))
		ret = ft_strcpy(ret, str + i + 1);
	free(str);
	return (ret);
}

static char		*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*new;

	if (!s1 || !s2 || !(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	if (!(new = ft_strcat(new, s1))
	|| !(new = ft_strcat(new, s2)))
		return (NULL);
	free(s1);
	return (new);
}

static t_file	*ft_get_file(t_file **f_list, const int fd)
{
	t_file	*file;

	file = *f_list;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	if (!(file = ft_memalloc(sizeof(t_file)))
	|| !(file->content = (char*)malloc(BUFF_SIZE + 1)))
		return (NULL);
	file->fd = fd;
	file->next = *f_list;
	*f_list = file;
	return (file);
}

static size_t	ft_strchrcpy(char **dst, char *src, char c)
{
	char *ptr;

	if (!dst || !src)
		return (0);
	ptr = src;
	while (*src && *src != c)
		src++;
	free(*dst);
	if (!(*dst = ft_strnew(src - ptr + 1)))
		return (0);
	*dst = ft_strncpy(*dst, ptr, (size_t)(src - ptr));
	return (src - ptr);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*f_list;
	char			buf[BUFF_SIZE + 1];
	ssize_t			ret;
	t_file			*file;
	size_t			i;

	if (fd < 0 || !line || !(*line = ft_strnew(0))
	|| read(fd, buf, 0) < 0 || !(file = ft_get_file(&f_list, fd)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(file->content = ft_strjoin_and_free(file->content, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	i = ft_strchrcpy(line, file->content, 10);
	if (ret < BUFF_SIZE && !ft_strlen(file->content))
	{
		ft_fddel(&f_list, fd);
		return (0);
	}
	file->content = ft_cut_str(file->content, i);
	return (1);
}
