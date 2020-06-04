
#include "../includes/minishell.h"

static int		exit_opt(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (1);
		s++;
	}
	return (0);
}

int				ft_exit(t_msh *msh)
{
	char	*err_arg;
	char	*err_num1;
	char	*err_num2;

	err_arg = "exit\nmsh: exit: too many arguments\n";
	err_num1 = "exit\nmsh: exit: ";
	err_num2= ": numeric argument required\n";
	if (msh->input[1])
	{
		if (exit_opt(msh->input[1]))
		{
			ft_putstr_fd(err_num1, 2);
			ft_putstr_fd(msh->input[1], 2);
			ft_putstr_fd(err_num2, 2);
			exit(EXIT_SUCCESS);
		}
		if (msh->input[2])
		{
			ft_putstr_fd(err_arg, 2);
			return (1);
		}
	}
	exit(EXIT_SUCCESS);
}
