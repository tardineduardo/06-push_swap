#include "../push_swap.h"

static void move_a_to_b(t_info *s)
{
	if (&(s->a)->next->cost < 0)
		while (s->b->next != s->b_to_move)
			rb(s, 1);
	if (s->a->next->cost > 0)
		while (s->b->next != s->b_to_move)
			rrb(s, 1);
	pb(s, 1);
	if (s->b->next->value >= s->hi_a->value)
		s->hi_a = ft_dclst_find_highest_int(&(s->a), offsetof(t_dll, value));
}


static void move_b_to_a(t_info *s)
{
	if (s->b->next->cost < 0)
		while (s->a->next != s->a_to_move)
			ra(s, 1);
	if (s->a->next->cost > 0)
		while (s->a->next != s->a_to_move)
			rra(s, 1);
	pa(s, 1);
	if (s->a->next->value <= s->lo_b->value)
		s->lo_b = ft_dclst_find_lowest_int(&(s->b), offsetof(t_dll, value));
}

void	move(t_info *s)
{


	if (s->a->next->cost > 900 && s->b->next->cost > 900)
	{
		rr(s, 1);
		return;
	}
	if (abs(s->a->next->cost) < abs(s->b->next->cost))
		move_a_to_b(s);
	else if (abs(s->a->next->cost) >= abs(s->b->next->cost))
		move_b_to_a(s);


}