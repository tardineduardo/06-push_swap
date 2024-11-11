#include "../push_swap.h"

static void	move_swp_a(t_table *s, t_dll *lowest)
{
	int	dist_nd_head;

	dist_nd_head = ft_dclst_dist_head_bidi(&(s->a), lowest);
	if (dist_nd_head > 0)
		while (lowest != s->a->next)
			ra(s, 1);
	if (dist_nd_head < 0)
		while (lowest->precedent != s->a)
			rra(s, 1);
	sa(s, 1);
	s->block_swap = true;
	return ;
}

static void	move_swp_b(t_table *s, t_dll *lowest)
{
	int	dist_nd_head;

	dist_nd_head = ft_dclst_dist_head_bidi(&(s->b), lowest);
	if (dist_nd_head > 0)
		while (lowest != s->b->next)
			rb(s, 1);
	if (dist_nd_head < 0)
		while (lowest->precedent != s->b)
			rrb(s, 1);
	sb(s, 1);
	s->block_swap = true;
	return ;	
}

static void move_swp(t_table *s, t_dll *lowest)
{
	if (s->dst_name == 'b')
		move_swp_a(s, lowest);
	else if (s->dst_name == 'a')
		move_swp_b(s, lowest);
	return ;
}