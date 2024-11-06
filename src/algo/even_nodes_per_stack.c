#include "../push_swap.h"

void	even_nodes_per_stack(t_info *s)
{
	int	half;
	half = (s->t_len/2);

	while(s->b_len != half && !(s->a_csort))
	{
		if (s->a->value < s->t_len/2)
			pb(s, 1);
		else
			rr(s, 1);

	}
	return ;
}