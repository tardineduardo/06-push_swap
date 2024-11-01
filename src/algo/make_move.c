#include "../push_swap.h"

static void move_opo(t_info *s, t_dll *lowest)
{
	if (s->dst_name == 'a')
	{
		if (lowest->opo_way_a == 'f')
		{
			while (lowest != s->b->next)
			{
//				if (swapping_works(s))
//					return ;
				rrb(s, 1);
			}
			while (lowest->adjacent != s->a)
			{
//				if (swapping_works(s))
//					return ;
				ra(s, 1);
			}
			pa(s, 1);
		}
		else if (lowest->opo_way_a == 'r')
		{
			while (lowest != s->b->next)
			{
//				if (swapping_works(s))
//					return ;
				rb(s, 1);
			}
			while (lowest->adjacent != s->a)
			{
//				if (swapping_works(s))
//					return ;
				rra(s, 1);
			}
			pa(s, 1);
		}
	}	
	if (s->dst_name == 'b')
	{
		if (lowest->opo_way_a == 'f')
		{
			while (lowest != s->a->next)
			{
//				if (swapping_works(s))
//					return ;
				ra(s, 1);
			}
			while (lowest->adjacent != s->b->next)
			{
//				if (swapping_works(s))
//					return ;
				rrb(s, 1);
			}
			pb(s, 1);
		}
		else if (lowest->opo_way_a == 'r')
		{
			while (lowest != s->a->next)
			{
//				if (swapping_works(s))
//					return ;
				ra(s, 1);
			}
			while (lowest->adjacent != s->b->next)
			{
//				if (swapping_works(s))
//					return ;
				rrb(s, 1);
			}
			pb(s, 1);
		}	
	}
}

static void move_rev(t_info *s, t_dll *lowest)
{
	if (s->dst_name == 'a')
	{
		while (lowest != s->b->next && lowest->adjacent != s->a)
		{
//			if (swapping_works(s))
//				return ;			
			rrr(s, 1);
		}
		while (lowest != s->b->next)
		{
//			if (ing_works(s))
//				return ;
			rrb(s, 1);
		}
		while (lowest->adjacent != s->a)
		{
//			if (ing_works(s))
//				return ;
			rra(s, 1);
		}
		pa(s, 1);
	}
	if (s->dst_name == 'b')
	{
		while (lowest != s->a->next && lowest->adjacent != s->b->next)
		{
//			if (ing_works(s))
//				return ;
			rrr(s, 1);
		}
		while (lowest != s->a->next)
		{
//			if (ing_works(s))
//				return ;
			rra(s, 1);
		}
		while (lowest->adjacent != s->b->next)
		{
//			if (ing_works(s))
//				return ;
			rrb(s, 1);
		}
		pb(s, 1);
	}
}

static void move_rot(t_info *s, t_dll *lowest)
{
	if (s->dst_name == 'a')
	{
		while (lowest != s->b->next && lowest->adjacent != s->a)
		{
//			if (ing_works(s))
//				return ;
			rr(s, 1);
		}
		while (lowest != s->b->next)
		{
//			if (ing_works(s))
//				return ;
			rb(s, 1);
		}
		while (lowest->adjacent != s->a)
		{
//			if (ing_works(s))
//				return ;
			ra(s, 1);
		}
		pa(s, 1);	
	}
	if (s->dst_name == 'b')
	{
		while (lowest != s->a->next && lowest->adjacent != s->b->next)
		{
//			if (ing_works(s))
//				return ;
			rr(s, 1);
		}
		while (lowest != s->a->next)
		{
//			if (ing_works(s))
//				return ;
			ra(s, 1);
		}
		while (lowest->adjacent != s->b->next)
		{
//			if (ing_works(s))
//				return ;
			rrb(s, 1);
		}
		pb(s, 1);
	}

}

void	pick_move(t_info *s, t_dll *lowest)
{
	if (lowest->move_rot)
		move_rot(s, lowest);
	else if (lowest->move_rev)
		move_rev(s, lowest);
	else if (lowest->move_opo)
		move_opo(s, lowest);
}


void	make_move(t_info *s)
{
	t_dll	*lowst;
	t_dll	*lowst_a;
	t_dll	*lowst_b;

	lowst_a = find_lowest_cost(&(s->a));
	lowst_b = find_lowest_cost(&(s->b));
	if (lowst_a->cost == lowst_b->cost)
	{
		if (s->a_len > s->b_len)
		{
			s->dst_name = 'b';
			lowst = lowst_a;
			s->last_moved = lowst;
		}
		if (s->a_len < s->b_len)
		{
			s->dst_name = 'a';
			lowst = lowst_b;
			s->last_moved = lowst;
		}
	}
	else
	{
		if (lowst_a->cost < lowst_b->cost)
		{
			s->dst_name = 'b';
			lowst = lowst_a;
			s->last_moved = lowst;
		}
		else if (lowst_a->cost > lowst_b->cost)
		{	
			s->dst_name = 'a';
			lowst = lowst_b;
			s->last_moved = lowst;
		}
	}
	pick_move(s, lowst);
}
