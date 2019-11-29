#include "libft/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "ft_printf.h"

void	ft_prompt(char *str);

/*char	*ft_strndup(char *str, int n)
{
	char *s2;

	if (!(s2 = ft_strnew(n)))
		return (NULL);
	return (ft_strncpy(s2, str, n));
}*/

char	*ft_strcut(char *str)
{
	int		i;

	while (str[i])
		i++;
	while (i > 0)
	{
		if (str[i] == '/')
		{
			str = ft_strndup(str, i);
			return (str);
		}
		else
			i--;
	}
	return (str);
}

char	*ft_cd(char *path, char *new)
{
	int				i;
	int				n;

	if (!(ft_strcmp(new, "..")))
	{
		path = ft_strcut(path);
		i = chdir(path);
	}
	else
	{
		if ((opendir(new)))
		{
			path = ft_strjoin(path, "/");
			path = ft_strjoin(path, new);
			i = chdir(path);
		}
		else
		{
			ft_printf("minishell : cd: %s: No such file or directory\n", new);
		}
	}
	return (path);
}

void	ft_prompt(char *str)
{
	ft_putstr(str);
	ft_putstr("> ");
}

int		yoyo(char *str)
{
	char	**tab;
	char	*path;
	char	oui[666];
	int		i;

	if (!(getcwd(oui, sizeof(oui))))
		return (-1);
	path = ft_strdup(oui);
	if (!(tab = ft_strsplit(str, ' ')))
		return (0);
	if (!(ft_strcmp(tab[0], "cd")) && (!(path = ft_cd(path, tab[1]))))
		return (-1);
	if (!(ft_strcmp(tab[0], "echo")))
	{
		i = 1;
		while (tab[i])
		{
			ft_putstr(tab[i++]);
			if (tab[i])
				ft_putchar(' ');
			else
				ft_putchar('\n');
		}
	}
	ft_prompt(path);
	return (1);
}

int		main(int ac, char **av)
{
	int		i;
	char	*line;

	i = 1;
	line = NULL;
	while (i)
	{
		i = get_next_line(0, &line);
		yoyo(line);
	}

	//	printf("\n");
	return 0;
}
