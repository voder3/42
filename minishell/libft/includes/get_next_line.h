/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:42:43 by artderva          #+#    #+#             */
/*   Updated: 2019/11/14 20:49:52 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 44
# include "libft.h"

int					get_next_line(const int fd, char **line);

typedef	struct		s_file
{
	char			*content;
	char			*beg;
	int				fd;
	struct s_file	*next;
}					t_file;

void				ft_fddel(t_file **f_list, int fd);
#endif
