/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:21 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:21 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdlib.h>

char	*ft_strjoinfree(char *s1, char *s2, int tofree)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)ft_memalloc(len + 1)))
		return (NULL);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	if (tofree == 1 || tofree == 3)
		free(s1);
	else if (tofree == 2 || tofree == 3)
		free(s2);
	return (str);
}
