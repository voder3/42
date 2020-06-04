#include "minishell.h"
#include "dirent.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

static char	*which_path(char *path, char *exec)
{
	char	*dst;

	dst = ft_strnew(ft_strlen(path) + ft_strlen(exec) + 1);
	ft_strcat(dst, path);
	ft_strcat(dst, "/");
	ft_strcat(dst, exec);
	return (dst);
}

int		ft_isdir(char *path)
{
	DIR		*dir;

	if (!path)
		return (0);
	if ((dir = opendir(path)))
	{
		closedir(dir);
		return (1);
	}
	return (0);
}

int		is_file(char *path, char *str)
{
	DIR			*dir;
	struct dirent		*dit;
	int			ret;
	char			*name;

	ret = 0;
	if (!*str)
		return (0);
	if (*str == '/')
		*str = '\0';
	name = *str ? str : str + 1;
	if (!(dir = opendir(path)))
	{
		*str = *str ? *str : '/';
		return (0);
	}
	while (!ret && (dit = readdir(dir)))
		if (!ft_strcmp(dit->d_name, name))
			ret = 1;
	closedir(dir);
	*str = *str ? *str : '/';
	return (ret);
}


char		*absolute_path(char *exec)
{
	if (ft_isdir(exec))
		ft_printf("msh: %s: Is a directory\n", exec);
	else if (is_file(exec, ft_strrchr(exec, '/')))
		return (exec);
	else
		ft_printf("msh: %s: No such file or directory\n", exec);
	return (NULL);
}

char		*ft_which(char *paths, char *exec)
{
	struct dirent	*file;
	char		**tab;
	DIR		*dir;
	int		i;

	i = -1;
	if (ft_strchr(exec, '/'))
		return (absolute_path(exec));
	if (!(paths && exec && (tab = ft_strsplit(paths, ':')))) //a modif
		return (NULL);
	while (tab[++i])
	{
		if (!(dir = opendir(tab[i])))
			continue;
		while ((file = readdir(dir)))
			if (ft_strcmp(file->d_name, exec) == 0)
				break ;
		closedir(dir);
		if (file)
			return (which_path(tab[i], exec));
	}
	ft_printf("msh: %s: command not found\n", exec);
	return (NULL);
}

char		**env_to_tab(t_list *env)
{
	char		**arr;
	t_list		*cpy;
	int		i;

	i = 0;
	cpy = env;
	while (cpy)
	{
		i++;
		cpy = cpy->next;
	}
	if (!(arr = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	i = 0;
	while (env)
	{
		arr[i] = ft_strjoin(((t_var*)(env->content))->tab[0], "=");
		arr[i] = ft_strjoin(arr[i], ((t_var*)(env->content))->tab[1]);
		env = env->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int		ft_is_exec(t_msh *msh)
{
	char		*exec;
	pid_t		pid;
	int		status;
	char		*path;

	path = ft_getenv(msh->env_var, "PATH");
	if ((exec = ft_which(path, msh->input[0])) == NULL)
		return 0;
	else
	{
		msh->envp = env_to_tab(msh->env_var);
		pid = fork();
		if (pid == 0)
			if (execve(exec, msh->input, msh->envp) == -1)
				return 0;
		if (pid == -1)
			ft_ex(NULL, "fork fail");
		else
			wait(&status);
	}
	return 0;
}
