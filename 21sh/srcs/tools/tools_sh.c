/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:12:21 by pacharbo          #+#    #+#             */
/*   Updated: 2020/07/01 14:12:21 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "ft_printf.h"
#include "var.h"
#include <stdlib.h>
#include <pwd.h>

void	ft_ex(char *error)
{
	ft_dprintf(STDERR_FILENO, "%s: %s", PROJECT, error);
	exit(EXIT_FAILURE);
}

void	protect_malloc(void *malloc)
{
	if (!malloc)
		ft_ex(EXMALLOC);
}

void	build_prompt_ps1(uint8_t update)
{
	struct passwd	*id;
	char			*logname;
	char			*pwd;
	char			*buf;
	static int		dont_touch = 0;

	if (((dont_touch = update)) || dont_touch)
		return ;
	if (!(id = getpwuid(getuid())))
		logname = ft_strncpy(ft_strnew(5), "USER", 5);
	else
		logname = ft_strdup(id->pw_name);
	if (!(pwd = getcwd(0, 0)))
		pwd = ft_strncpy(ft_strnew(4), "PWD", 4);
	ft_asprintf(&buf, "[%s][%s] ~> ", id->pw_name, pwd);
	setvar_update(find_var(cfg_shell()->intern, "PS1"), buf);
	ft_strdel(&logname);
	ft_strdel(&pwd);
	ft_strdel(&buf);
}
