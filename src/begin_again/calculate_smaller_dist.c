
#include "../push_swap.h"

void calculate_smaller_dist(t_info *s)
{
	int	top_a_s_dist;
	int top_b_s_dist;

	t_dll *smllest_in_a;
	t_dll *biggest_in_b;
	smllest_in_a = ft_dclst_find_lowest_int(&(s->a), offsetof(t_dll, value));
	biggest_in_b = ft_dclst_find_highest_int(&(s->b), offsetof(t_dll, value));

	


}