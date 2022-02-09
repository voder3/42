/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:06:45 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:06:45 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1083

int					get_next_line(const int fd, char **line);

typedef struct		s_gnl
{
	char			**content;
	int				num;
	struct s_gnl	*next;
}					t_gnl;
#endif
