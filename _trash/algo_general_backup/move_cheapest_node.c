#include "../push_swap.h"

static void rotate_backwards(t_info *s)
{
	if (s->dst_name == 'a')
	{
		while (s->cheap_n != s->b->next && s->cheap_n->adjacent != s->a)
		{
			if (swapping_works(s))
				continue ;			
			rrr(s, 1);
		}
		while (s->cheap_n != s->b->next)
		{
			if (swapping_works(s))
				continue ;
			rrb(s, 1);
		}
		while (s->cheap_n->adjacent != s->a)
		{
			if (swapping_works(s))
				continue ;
			rra(s, 1);
		}
		pa(s, 1);
	}
	if (s->dst_name == 'b')
	{
		while (s->cheap_n != s->a->next && s->cheap_n->adjacent != s->b->next)
		{
			if (swapping_works(s))
				continue ;
			rrr(s, 1);
		}
		while (s->cheap_n != s->a->next)
		{
			if (swapping_works(s))
				continue ;
			rra(s, 1);
		}
		while (s->cheap_n->adjacent != s->b->next)
		{
			if (swapping_works(s))
				continue ;
			rrb(s, 1);
		}
		pb(s, 1);
	}
}



static void rotate_forward(t_info *s)
{
	if (s->dst_name == 'a')
	{
		while (s->cheap_n != s->b->next && s->cheap_n->adjacent != s->a)
		{
			if (swapping_works(s))
				continue ;
			rr(s, 1);
		}
		while (s->cheap_n != s->b->next)
		{
			if (swapping_works(s))
				continue ;
			rb(s, 1);
		}
		while (s->cheap_n->adjacent != s->a)
		{
			if (swapping_works(s))
				continue ;
			ra(s, 1);
		}
		pa(s, 1);	
	}
	if (s->dst_name == 'b')
	{
		while (s->cheap_n != s->a->next && s->cheap_n->adjacent != s->b->next)
		{
			if (swapping_works(s))
				continue ;
			rr(s, 1);
		}
		while (s->cheap_n != s->a)
		{
			if (swapping_works(s))
				continue ;
			ra(s, 1);
		}
		while (s->cheap_n->adjacent != s->b->next)
		{
			if (swapping_works(s))
				continue ;
			rrb(s, 1);
		}
		pb(s, 1);
	}

}

void	move_cheap_n(t_info *s)
{
	if (s->cheap_n->cost < 0)
		rotate_backwards(s);	

	else if (s->cheap_n->cost > 0)
		rotate_forward(s);

}
