#include "../push_swap.h"

bool ft_is_stack_sorted(t_dlist **tail, char s)
{
	int 	i;
	int		j;
	t_dlist *trav;

	trav = *tail;
	while(trav->next->next != *tail)
	{
		i = ((t_node *)((*tail)->content))->value;
		j = ((t_node *)((*tail)->next->content))->value;
		if (s == 'a')
			if (i > j)
				return (false);
		else if (s == 'b')
			if (i < j)
				return (false);
	}
	return (true);
}


bool ft_is_circle_sorted(t_dlist **tail, char s)
{
	


}



