#include "../push_swap.h"

void	even_nodes_per_stack(t_info *s)
{
	int	half;
	half = (s->a_len / 3);

	if (s->a_len > s->b_len)
	{
		while(s->b_len != half && !(s->a_csort))
		{
			pb(s, 1);
		}
	}
	if (s->b_len > s->a_len)
	{
		while(s->b_len != half && !(s->a_csort))
		{
			pa(s, 1);
		}
	}
}