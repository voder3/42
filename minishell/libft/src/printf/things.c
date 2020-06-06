/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   things.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:30:25 by artderva          #+#    #+#             */
/*   Updated: 2020/06/06 17:05:13 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_straddcb(int add, char *str)
{
	char	*ret;
	int		i;

	if (!(ret = ft_strnew(ft_strlen(str) + 1)))
		return (NULL);
	ret[0] = add;
	i = 0;
	while (str[i])
	{
		ret[i + 1] = str[i];
		i++;
	}
	free(str);
	return (ret);
}

char	*ft_straddc(char *str, char c)
{
	int		i;
	int		n;
	char	*new;

	i = 0;
	n = ft_strlen(str);
	if (!(new = ft_strnew(n + 1)))
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	free(str);
	return (new);
}

char	*ft_strndup(char *src, int n)
{
	int		len;
	char	*dup;
	int		i;

	i = -1;
	len = (int)ft_strlen(src) > n ? n : (int)ft_strlen(src);
	if (!(dup = ft_strnew(len + 1)))
		return (NULL);
	while (src[++i] && len)
	{
		dup[i] = src[i];
		len--;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_addzero(char *str, int len)
{
	char	*tmp;

	if (!(tmp = ft_strnew(len)))
		return (NULL);
	ft_memset((void *)tmp, '0', len);
	if (!(str = ft_sjoin(tmp, str)))
		return (NULL);
	return (str);
}

char	*ft_minus(t_prin fors, char *str, char *tmp)
{
	if (fors.flag[2] == '1' && (!(str = ft_sjoin(str, tmp))))
		return (ft_free2(str, tmp));
	else if (fors.flag[2] == '0' && !(str = ft_sjoin(tmp, str)))
		return (ft_free2(str, tmp));
	return (str);
}
