/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:56:16 by artderva          #+#    #+#             */
/*   Updated: 2019/07/16 16:58:28 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*str;

	if (!(str = ft_strjoin(s1, s2)))
		return (NULL);
	ft_strdel(&s1);
	return (str);
}
