#include "../push_swap.h"

void	split_by_order(t_info *s)
{
	t_dll *trav;
	trav = s->a->next;
	int count;

	count = 0;
	while (count < 3)
	{
		if (s->a->next->value < s->t_len / 2)
		{
			ra(s, 1);
			count++;
		}
		else
			pb(s, 1);
	}
	while (s->a_len > s->t_len / 3)
		pb(s, 1);
	return;
}



