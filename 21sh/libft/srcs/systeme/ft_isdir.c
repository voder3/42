/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:03:23 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:03:23 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>

int		ft_isdir(char *path, int link)
{
	struct stat info;

	if (!link)
		lstat(path, &info);
	else
		stat(path, &info);
	return (S_ISDIR(info.st_mode));
}
