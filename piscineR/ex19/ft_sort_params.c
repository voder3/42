/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:31:23 by artderva          #+#    #+#             */
/*   Updated: 2018/11/07 14:46:36 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (!(s1[i]))
			return (0);
		else
			i++;
	}
	return (s1[i] - s2[i]);
}

int		main(int ac, char **av)
{
	int		i;
	char	*swap;

	i = 0;
	while (ac - 1 > i)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			swap = av[i];
			av[i] = av[i + 1];
			av[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while (av[++i])
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
	}
}
