
#include "get_next_line.h"

void	ft_fddel(t_file **f_list, int fd)
{
	t_file	*tmp;
	t_file	*curr;

	curr = *f_list;
	if ((*f_list)->fd == fd)
	{
		ft_strdel(&((*f_list)->content));
		tmp = (*f_list)->next;
		free(*f_list);
		*f_list = tmp;
	}
	else
		while (curr->next)
		{
			tmp = curr->next;
			if (tmp->fd == fd)
			{
				ft_strdel(&(tmp->content));
				curr->next = tmp->next;
				free(tmp);
				break ;
			}
			curr = tmp;
		}
}
