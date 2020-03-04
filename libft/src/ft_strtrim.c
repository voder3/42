/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:43:37 by artderva          #+#    #+#             */
/*   Updated: 2018/11/16 19:55:53 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SPA(c) (c == ' ' || c == '\n' || c == '\t')

char	*ft_strtrim(char const *s)
{
	char			*str;
	size_t			n;
	unsigned int	start;
	unsigned int	len;

	if (!s)
		return (NULL);
	start = 0;
	while (SPA(s[start]))
		start++;
	if (!s[start])
		return (ft_strnew(1));
	n = ft_strlen(s) - 1;
	while (SPA(s[n]))
		n--;
	n++;
	len = n - start;
	str = ft_strsub(s, start, len);
	return (str);
}
