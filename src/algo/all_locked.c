#include "../push_swap.h"

bool all_locked(t_info *s)
{
	t_dll	*trav;
	int		i;

	i = 0;
	if (s->a)
	{
		trav = s->a->next;
		while (i < s->a_len)
		{
			if (trav->cost != 999)
				return (false);
			trav = trav->next;
			i++;
		}
	}
	i = 0;
	if (s->b)
	{
		trav = s->b->next;
		while (i < s->b_len)
		{
			if (trav->cost != 999)
				return (false);
			trav = trav->next;
			i++;
		}
	}
	return (true);
}
