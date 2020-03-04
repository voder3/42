/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:03:38 by artderva          #+#    #+#             */
/*   Updated: 2019/05/16 16:31:29 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!(str = ft_strjoin(s1, s2)))
		return (NULL);
	ft_strdel((char**)&s1);
	ft_strdel((char**)&s2);
	return (str);
}
