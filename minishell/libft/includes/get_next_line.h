/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:42:43 by artderva          #+#    #+#             */
/*   Updated: 2020/06/06 17:08:57 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 44
# include "libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_gnl
{
	char			**content;
	int				num;
	struct s_gnl	*next;
}					t_gnl;

#endif
