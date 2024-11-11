#include "../push_swap.h"

bool	swapping_works(t_table *s)
{
	bool swap_a;
	bool swap_b;
    t_dll *top_a;
    t_dll *top_b;
	
	swap_a = false;
	swap_b = false;
 	
	if(s->a) top_a = s->a->next;
	if(s->b) top_b = s->b->next;
	
	if (s->a && !(s->a_partially_sorted))
		if (top_a->value > top_a->next->value
		&& top_a->value != s->lo_a->value
		&& top_a->next->value != s->hi_a->value)
		swap_a = true;
	
	if (s->b && !(s->b_partially_sorted))
		if (top_b->value < top_b->next->value 
			&& top_b->value != s->hi_b->value && top_b->next->value != s->lo_b->value)		
			swap_b = true;
	if (!swap_a && !swap_b)
		return (false);
	else if (swap_a && swap_b)
		ss(s, 1);
	else if (swap_a)
		sa(s, 1);
	else if (swap_b)
		sb(s, 1);
	update_sorted_status(s);
	return (true);
}

bool	swapping_back_works(t_table *s)
{
	bool swap_a;
	bool swap_b;
    t_dll *top_a;
    t_dll *top_b;
	
	swap_a = false;
	swap_b = false;
	if(s->a) top_a = s->a->next;
	if(s->b) top_b = s->b->next;

	if (s->a && !(s->a_partially_sorted))
		if (s->a->value > top_a->value					//OK
		&& s->a->value >= s->t_len/2
		&& top_a->value >= s->t_len/2
	//	&& top_a->value != s->lo_a->value				//OK
		&& s->a->value != s->t_len - 1)
		swap_a = true;
	if (s->b && !(s->b_partially_sorted))
		if (s->b->value < top_b->value					//ok
		&& s->b->value < s->t_len/2
		&& top_b->value < s->t_len/2
	//	&& top_b->value != s->hi_b->value
		&& s->b->value != 0) 
		swap_b = true;
	if (!swap_a && !swap_b)
		return (false);
	else if (swap_a && swap_b)
	{
		rrr(s, 1);
		ss(s, 1);
	}
	else if (swap_a)
	{
		rra(s, 1);
		sa(s, 1);
	}
	else if (swap_b)
	{
		rrb(s, 1);
		sb(s, 1);
	}
	update_sorted_status(s);
	return (true);
}