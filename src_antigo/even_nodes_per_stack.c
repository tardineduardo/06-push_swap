#include "../push_swap.h"

void	even_nodes_per_stack(t_table *s)
{
	int	half;
	half = (s->a_len / 2);

	if (s->a_len > s->b_len)
	{
		while(s->b_len != half && !(s->a_partially_sorted))
		{
			pb(s, 1);
		}
	}
	if (s->b_len > s->a_len)
	{
		while(s->b_len != half && !(s->a_partially_sorted))
		{
			pa(s, 1);
		}
	}
}