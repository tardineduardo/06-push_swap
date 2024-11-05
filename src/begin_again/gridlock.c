#include "../push_swap.h"

bool	gridlock(t_info *s)
{
	t_dll *trav;
	int		i;

	if (s->a)
	{
		i = 0;
		trav = s->a;
		while (i < s->a_len)
		{
			if (trav->value > s->t_len / 2)
				return (false);
			trav = trav->next;
			i++;
		}
	}
	if (s->b)
	{
		i = 0;
		trav = s->b;
		while (i < s->b_len)
		{
			if (trav->value < s->t_len / 2)
				return (false);
			trav = trav->next;
			i++;
		}
	}
	return (true);
}
