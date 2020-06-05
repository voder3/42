/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:21:30 by artderva          #+#    #+#             */
/*   Updated: 2020/06/05 18:36:05 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdio.h>

int		ft_stchr(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		else
			i++;
	}
	if (str[i] == c)
		return (i);
	return (0);
}

char	*brackets_dol(char *str, int *n, int *len, t_list *env)
{
	char	*ret;

	if (!(*n = ft_stchr(str, '}')))
		return (ft_strnew(0));
	if (!(ret = ft_strsub(str, 2, *n - 2)))
		ft_ex(NULL, "memory allocation failed");
	if (!(ret = ft_getenvval(env, ret)))
	{
		if (!(ret = ft_strnew(0)))
			ft_ex(NULL, "memory allocation failed");
	}
	*len = ft_strlen(ret);
	if (str[*n + 1] && (!(ret = ft_strjoin1(ret, str + *n + 1))))
		ft_ex(NULL, "memory allocation failed");
	*n += 1;
	return (ret);
}

char	*reg_dol(char *str, int n, int *len, t_list *env)
{
	char	*ret;

	while (ft_isalnum(str[n]) || str[n] == '_')
		n++;
	if (!(ret = ft_strsub(str, 1, n - 1)))
		ft_ex(NULL, "memory allocation failed");
	if (!(ret = ft_getenvval(env, ret)))
	{
		if (!(ret = ft_strnew(0)))
			ft_ex(NULL, "memory allocation failed");
	}
	*len = ft_strlen(ret);
	if (str[n + 1] && (!(ret = ft_strjoin(ret, str + n))))
		ft_ex(NULL, "memory allocation failed");
	return (ret);
}

char	*ft_dollar(char *str, t_list *env, int *len)
{
	char	*ret;
	char	*tmp;
	int		n;

	n = 1;
	if (!str[1])
	{
		*len += 2;
		return (str);
	}
	if (str[1] == '$')
		return (str[2] ? str + 2 : ft_strnew(0));
	if ((!(ft_isalnum(str[1])) && str[1] != '{' && str[1] != '_'))
	{
		*len += 2;
		return (str);
	}
	else if (str[1] == '{')
		ret = brackets_dol(str, &n, len, env);
	else
		ret = reg_dol(str, n, len, env);
	return (ret);
}

char	*ft_dolls(char *str, t_list *env, int *len)
{
	char	*prev;
	char	*tmp;
	int		n;

	n = *len;
	while (str[n] != '$')
		n++;
	if (n && !(prev = ft_strsub(str, 0, n)))
		ft_ex(NULL, "memory allocation failed");
	if (!(str = ft_dollar(str + n, env, len)))
		ft_ex(NULL, "memory allocation failed");
	if (n && (!(str = ft_strjoin(prev, str))))
		ft_ex(NULL, "memory allocation failed");
	return (str);
}
