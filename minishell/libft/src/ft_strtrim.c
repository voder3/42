/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:43:37 by artderva          #+#    #+#             */
/*   Updated: 2020/06/12 15:49:46 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	size_t			n;
	unsigned int	st;
	unsigned int	len;

	if (!s)
		return (NULL);
	st = 0;
	while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
		st++;
	if (!s[st])
		return (ft_strnew(1));
	n = ft_strlen(s) - 1;
	while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
		n--;
	n++;
	len = n - st;
	str = ft_strsub(s, st, len);
	return (str);
}
