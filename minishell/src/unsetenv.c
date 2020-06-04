#include "minishell.h"

int			ft_unsetenv(t_msh *msh)
{
	t_list	*env;
	t_list 	*prev;

	env = msh->env_var;
	prev = NULL;
	while (env)
	{
		if (!ft_strcmp(msh->input[1], (((t_var *)(env->content))->tab[0])))
		{
			if (!prev)
				msh->env_var = env->next;
			else
				prev->next = env->next;
			ft_del_tab(env->content);
			free(env);
			return (0);
		}
		prev = env;
		env = env->next;
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msh->input[1], 2);
	ft_putendl_fd(": no environment variable", 2);
	return (1);
}
