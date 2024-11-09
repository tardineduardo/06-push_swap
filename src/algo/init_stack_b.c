#include "../push_swap.h"

void	ft_init_stack_b(t_table *s)
{
	while (s->b_len < 1)
	{
		if (s->a->next->value > s->t_len / 2)
			ra(s, 1);
		else
			pb(s, 1);
	}
	return ;
}
