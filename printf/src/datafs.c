/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datafs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:34:02 by artderva          #+#    #+#             */
/*   Updated: 2019/05/21 18:04:49 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_getflag(char **s, t_prin *fors)
{
	int i;

	i = -1;
	while (i++ < 4)
		fors->flag[i] = '0';
	while (**s == '#' || **s == '0' || **s == '-' || **s == '+' || **s == ' ')
	{
		if (**s == '#')
			fors->flag[0] = '1';
		if (**s == '0')
			fors->flag[1] = '1';
		if (**s == '-')
			fors->flag[2] = '1';
		if (**s == '+')
			fors->flag[3] = '1';
		if (**s == ' ')
			fors->flag[4] = '1';
		s[0]++;
	}
}

static void	ft_getlenw(char **str, t_prin *fors)
{
	fors->lenw = 0;
	if (**str >= '1' && **str <= '9')
	{
		fors->lenw = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			str[0]++;
	}
}

static void	ft_getprec(char **str, t_prin *fors)
{
	fors->prec = -1;
	if (**str == '.')
	{
		str[0]++;
		fors->prec = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			str[0]++;
	}
}

static void	ft_getlenm(char **str, t_prin *fors)
{
	fors->lenm = 0;
	if (**str == 'h')
	{
		str[0]++;
		fors->lenm = **str == 'h' ? 2 : 1;
		if (fors->lenm == 2)
			str[0]++;
	}
	if (**str == 'l')
	{
		str[0]++;
		fors->lenm = **str == 'l' ? 4 : 3;
		if (fors->lenm == 4)
			str[0]++;
	}
	if (**str == 'L')
	{
		str[0]++;
		fors->lenm = 5;
	}
}

int			ft_getfs(char **str, t_prin *fors)
{
	if (**str)
	{
		ft_getflag(str, fors);
		ft_getlenw(str, fors);
		ft_getprec(str, fors);
		ft_getlenm(str, fors);
	}
	while (!(ft_strchr("cspdiouxX%", **str)))
		str[0]++;
	if (**str)
		fors->type = **str;
	else
		return (-1);
	return (1);
}
