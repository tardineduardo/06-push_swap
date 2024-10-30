#include "../push_swap.h"

void	move_cheapest_node(t_info *s)
{
	move_node_to_top_source(s, s->cheapest_node);
	ft_play_print_values(&(s->a), &(s->b));

swapping_works(s);

	repostion_dst_stack(s, s->cheapest_node);
	ft_play_print_values(&(s->a), &(s->b));

	if (s->dst_name == 'a')
		pa(s, 1);
	if (s->dst_name == 'b')
		pb(s, 1);
	calculate_all_costs(s);
	ft_play_print_values(&(s->a), &(s->b));
}
