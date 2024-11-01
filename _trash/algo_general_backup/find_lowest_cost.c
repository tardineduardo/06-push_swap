#include "../push_swap.h"

void	find_lowest_cost(t_info *s)
{
	t_dll *cheaper_a;
	t_dll *cheaper_b;

	cheaper_a = ft_dclst_find_lowest_abs(&(s->a), offsetof(t_dll, cost));
	cheaper_b = ft_dclst_find_lowest_abs(&(s->b), offsetof(t_dll, cost));

	if (abs(cheaper_a->cost) < abs(cheaper_b->cost) || s->a_len > s->b_len)
	{
		s->cheap_n = cheaper_a;
		s->cheap_s = s->a;
		s->dst_s = s->b;
		s->dst_name = 'b';
	}
	else if (abs(cheaper_a->cost) > abs(cheaper_b->cost) || s->a_len <= s->b_len)
	{
		s->cheap_n = cheaper_b;
		s->cheap_s = s->b;
		s->dst_s = s->a;
		s->dst_name = 'a';
	}
}
