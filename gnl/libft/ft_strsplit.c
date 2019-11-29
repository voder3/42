/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:31:15 by artderva          #+#    #+#             */
/*   Updated: 2018/11/22 18:26:23 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(const char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 1;
	if (str[0] != c)
		count++;
	while (str[i])
	{
		if ((!(str[i] == c)) && str[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_lw(const char *str, int i, char c)
{
	int	j;

	j = 0;
	while (str[i + j] != c && str[i + j])
		j++;
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	j = 0;
	i = 0;
	if ((!s) || (!(tab = (char **)malloc(sizeof(s) * (ft_words(s, c) + 1)))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			k = 0;
			if (!(tab[j] = (char *)malloc(sizeof(char) * ft_lw(s, i, c) + 1)))
				return (NULL);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
