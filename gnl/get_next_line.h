/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:42:43 by artderva          #+#    #+#             */
/*   Updated: 2018/12/12 17:01:33 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 44
# include "libft/libft.h"

int					get_next_line(const int fd, char **line);

typedef	struct		s_file
{
	char			*cont;
	int				fd;
	struct s_file	*next;
}					t_file;

#endif
