/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:32:57 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:33:02 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nbwords(char *str, char *set)
{
	int words;

	words = 0;
	while (*str)
	{
		if (!ft_strchr(set, *str))
		{
			words++;
			while (*str && !ft_strchr(set, *str))
				str++;
		}
		while (*str && ft_strchr(set, *str))
			str++;
	}
	return (words);
}

int		word_len(char *str, char *set)
{
	int		ret;

	ret = 0;
	while (!ft_strchr(set, *str))
	{
		ret++;
		str++;
	}
	return (ret);
}

char	**ft_split(char *str, char *set)
{
	char	**ret;
	int		wlen;
	int		i;

	i = 0;
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * (nbwords(str, set) + 1))))
		return (0);
	while (*str)
	{
		if (!ft_strchr(set, *str))
		{
			wlen = word_len(str, set);
			if (!(ret[i] = ft_strndup(str, wlen)))
			{
				ft_del_tab((void**)ret);
				return (0);
			}
			str += wlen;
			i++;
		}
		while (*str && ft_strchr(set, *str))
			str++;
	}
	return (ret);
}
