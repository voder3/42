/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expanstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:21:30 by artderva          #+#    #+#             */
/*   Updated: 2020/01/13 16:30:40 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/minishell.h"
#include <stdio.h>

char	*ft_getenvval(t_list *env, char *str)
{
	char	*val;

	while (env)
	{
		if (!ft_strcmp(((t_var *)(env->content))->name, str))
		{
			if (!(val = ft_strdup(((t_var *)(env->content))->value)))
				return (NULL);
			return (val);
		}
		env = env->next;
	}
	return (NULL);
}

char	*ft_tild(char *str, t_list *env)
{
	char	*ret;

	if (str[1] == '/')
	{
		if (!(ret = ft_getenvval(env, "HOME")))
			return (NULL);
		if (!(ret = ft_strjoin1(ret, "/")))
			return (NULL);
		if (!(ret = ft_strjoin1(ret, str + 2)))
			return (NULL);
	}
	if (str[1] == '+')
	{
		if (!(ret = ft_getenvval(env, "PWD")))
		{
			if (!(ret = ft_strdup("~+")))
				return (NULL);
		}
		if (!(ret = ft_strjoin1(ret, str + 2)))
				return (NULL);
	}
	if (str[1] && (!(ft_strchr("+-/", str[1]))) &&
			(!(ret = ft_strjoin("~", str + 1))))
			return (NULL); 
	return (ret);
}

char	*ft_tilde(char *str, t_list *env)
{
	char	*ret;

	if (str[1] == '\0' && (!(ret = ft_getenvval(env, "HOME"))))
			return (NULL);
	if (str[1] == '-')
	{
		if (!(ret = ft_getenvval(env, "OLDPWD")))
		{
			if (!(ret = ft_strdup("~-")))
				return (NULL);
		}
		if (!(ret = ft_strjoin1(ret, str + 2)))
			return (NULL);
	}
	if (!(ret = ft_tild(str, env)))
		return (NULL);
	return (ret);
}

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

char	*ft_dollar(char *str, t_list *env)
{
	char	*ret;
	char	*tmp;
	int		n;

	n = 1;
	if (str[1] == '{')
	{
		if (!(n = ft_stchr(str, '}')))
			return (NULL);
		if (!(ret = ft_strsub(str, 2, n - 2)))
			return (NULL);
		if (!(ret = ft_getenvval(env, ret)))
			return (NULL);
		if (str[n + 1] && (!(ret = ft_strjoin1(ret, str + n + 1))))
			return (NULL);
	}
	else
	{
		while (ft_isalnum(str[n]) || str[n] == '_')
			n++;
		if (!(ret = ft_strsub(str, 1, n - 1)))
			return (NULL);
		if (!(ret = ft_getenvval(env, ret)))
		{
			if (!(ret = ft_strnew(0)))
				return (NULL);
		}
		if (str[n + 1] && (!(ret = ft_strjoin(ret, str + n))))
			return (NULL);
	}
	if (str[n] && (n += ft_stchr(str + n - 1, '$')))
	{
//		printf("n = %d\nret = %s\nstr = %s\n", n, ret, str + n - 1);
		if (!(tmp = ft_dollar(str + n - 1 , env)))
		{
			if (!(tmp = ft_strnew(0)))
				return (NULL);
		}
		while (ft_isalnum(str[n]) || str[n] == '_')
			n++;
		if (!(ret = ft_strsub(ret, 0, ft_stchr(ret, '$'))))
			return (NULL);
		if (!(ret = ft_strjoin(ret, tmp)))
			return (NULL);
	}
	return (ret);
}

char	*ft_expanstr(char *str, t_list *env)
{
	if (str[0] == '~' && !(str = (ft_tilde(str, env))))
		return (NULL);
	if (str[0] == '$' && (!(str = ft_dollar(str, env))))
		return (NULL);
	return (str);
}

char	**ft_exp_str(char	**input, t_list *env)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (!(input[i] = ft_expanstr(input[i], env)))
			return (NULL);
		i++;
	}
	return (input);
}
