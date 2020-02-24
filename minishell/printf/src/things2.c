/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   things2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:42:50 by artderva          #+#    #+#             */
/*   Updated: 2019/07/16 17:15:53 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_free(char *str)
{
	ft_strdel(&str);
	return (NULL);
}

char	*ft_free2(char *str, char *str2)
{
	ft_strdel(&str);
	ft_strdel(&str2);
	return (NULL);
}

int		ft_free3(char *str)
{
	ft_strdel(&str);
	return (-1);
}
