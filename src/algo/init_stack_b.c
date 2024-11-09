#include "../push_swap.h"

void	send_two_lower_values_to_stack_b(t_table *s)
{
	t_dll *trav;
	trav = s->a->next;

	while (s->b_len < 1)
	{
		if (s->a->next->value > s->t_len / 2)
			ra(s, 1);
		else
			pb(s, 1);
	}
	return;
}
