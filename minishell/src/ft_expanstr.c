/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expanstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:21:30 by artderva          #+#    #+#             */
/*   Updated: 2020/06/05 18:34:52 by artderva         ###   ########.fr       */
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
				ft_ex(NULL, "memory allocation failed");
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
			ft_ex(NULL, "memory allocation failed");
		if (!(ret = ft_strjoin1(ret, "/")))
			ft_ex(NULL, "memory allocation failed");
		if (!(ret = ft_strjoin1(ret, str + 2)))
			ft_ex(NULL, "memory allocation failed");
	}
	if (str[1] == '+')
	{
		if (!(ret = ft_getenvval(env, "PWD")))
		{
			if (!(ret = ft_strdup("~+")))
				ft_ex(NULL, "memory allocation failed");
		}
		if (!(ret = ft_strjoin1(ret, str + 2)))
			ft_ex(NULL, "memory allocation failed");
	}
	if (str[1] && (!(ft_strchr("+-/", str[1]))) &&
			(!(ret = ft_strjoin("~", str + 1))))
		ft_ex(NULL, "memory allocation failed");
	return (ret);
}

char	*ft_tilde(char *str, t_list *env)
{
	char	*ret;

	if (str[1] == '\0')
	{
		if (!(ret = ft_getenvval(env, "HOME")))
		{
			if (!(ret = ft_strnew(0)))
				ft_ex(NULL, "memory allocation failed");
		}
	}
	if (str[1] == '-')
	{
		if (!(ret = ft_getenvval(env, "OLDPWD")))
		{
			if (!(ret = ft_strdup("~-")))
				ft_ex(NULL, "memory allocation failed");
		}
		if (!(ret = ft_strjoin1(ret, str + 2)))
			ft_ex(NULL, "memory allocation failed");
	}
	if (!(ret = ft_tild(str, env)))
		ft_ex(NULL, "memory allocation failed");
	return (ret);
}

char	*ft_expanstr(char *str, t_list *env)
{
	int	len;

	len = 0;
	if (str[0] == '~' && !(str = (ft_tilde(str, env))))
		ft_ex(NULL, "memory allocation failed");
	while (ft_strchr(str + len, '$'))
	{
		if (!(str = ft_dolls(str, env, &len)))
			ft_ex(NULL, "memory allocation failed");
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
