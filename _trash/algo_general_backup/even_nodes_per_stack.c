#include "../push_swap.h"

void	even_nodes_per_stack(t_info *s)
{
	int	half;

	half = (s->a_len / 4);
	if (half < 3)
		half = 3;

	while(s->b_len != half && !(s->a_csort))
	{
		if (!(swapping_works(s)))
			pb(s, 1);
	}
}