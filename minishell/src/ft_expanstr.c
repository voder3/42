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

#include <minishell.h>
#include <stdio.h>

char	*ft_getenvval(t_list *env, char *str)
{
	char	*val;

	while (env)
	{
		if (!ft_strcmp(((t_var *)(env->content))->tab[0], str))
		{
			if (!(val = ft_strdup(((t_var *)(env->content))->tab[1])))
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

char	*ft_dollar(char *str, t_list *env, int *len)
{
	char	*ret;
	char	*tmp;
	int		n;

	n = *len + 1;
	if (!str[*len + 1])
	{
		*len += 2;
		return (str);
	}
	if (str[*len + 1] == '$')
		return (str[2] ? str + 2 : ft_strnew(0));
	if ((!(ft_isalnum(str[*len + 1])) &&
		str[*len + 1] != '{' && str[*len + 1] != '_')) //char specio
	{
		*len += 2;
		return (str);
	}
	else if (str[1] == '{')
	{
		if (!(n = ft_stchr(str, '}')))
			return (ft_strnew(0));
		if (!(ret = ft_strsub(str, 2, n - 2)))
			return (NULL);
		if (!(ret = ft_getenvval(env, ret)) && (!(ret = ft_strnew(0))))
			return (NULL);
		*len = ft_strlen(ret);
		if (str[n + 1] && (!(ret = ft_strjoin1(ret, str + n + 1))))
			return (NULL);
		n += 1;
	}
	else
	{
		while (ft_isalnum(str[n]) || str[n] == '_')
			n++;
		if (!(ret = ft_strsub(str, 1, n - 1)))
			return (NULL);
		if (!(ret = ft_getenvval(env, ret)) && (!(ret = ft_strnew(0))))
			return (NULL);
		*len = ft_strlen(ret);
		if (str[n + 1] && (!(ret = ft_strjoin(ret, str + n))))//si char specio encore
			return (NULL);
	}
	return (ret);
}

char	*ft_dolls(char *str, t_list *env, int *len)
{
	char	*prev;
	char	*tmp;
	int	n;

	n = *len;
	while (str[n] != '$')
		n++;
	if (n && !(prev = ft_strsub(str, 0, n)))
		return (NULL);
	if (!(str = ft_dollar(str + n, env, len)))
		return (NULL);
	if (n && (!(str = ft_strjoin(prev, str))))
		return (NULL);
	return (str);
}

char	*ft_expanstr(char *str, t_list *env)
{
	int 	len;

	len = 0;
	if (str[0] == '~' && !(str = (ft_tilde(str, env))))
		return (NULL);
	while (ft_strchr(str + len, '$'))
	{
		if (!(str = ft_dolls(str, env, &len)))
			return (NULL);
	}
	return (str);
}

char	**ft_exp_str(char **input, t_list *env)
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
