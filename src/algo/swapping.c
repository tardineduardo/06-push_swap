/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:08:06 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/05 20:49:38 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	swapping_works(t_info *s)
{
	bool swap_a;
	bool swap_b;
    t_dll *top_a;
    t_dll *top_b;
	
	swap_a = false;
	swap_b = false;
 	top_a = s->a->next;
	top_b = s->b->next;
	if (s->a != NULL && !(s->a_midsort))
		if (top_a->value > top_a->next->value && top_a->value >= s->t_len/2
		&& top_a->next->value > s->t_len/2 && top_a->value != s->lo_a->value
		&& top_a->next->value != s->hi_a->value)
		swap_a = true;
	if (s->b != NULL && !(s->b_midsort))
		if (top_b->value < top_b->next->value 
		&& top_b->value < s->t_len/2 && top_b->next->value < s->t_len/2
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


bool	swapping_back_works(t_info *s)
{
	bool swap_a;
	bool swap_b;
    t_dll *top_a;
    t_dll *top_b;
	
	swap_a = false;
	swap_b = false;
 	top_a = s->a->next;
	top_b = s->b->next;

	if (s->a != NULL && !(s->a_midsort))
		if (s->a->value > top_a->value					//OK
		&& s->a->value >= s->t_len/2
		&& top_a->value >= s->t_len/2
		&& top_a->value != s->lo_a->value				//OK
		&& s->a->value != s->hi_a->value)
		swap_a = true;
	if (s->b != NULL && !(s->b_midsort))
		if (s->b->value < top_b->value					//ok
		&& s->b->value < s->t_len/2
		&& top_b->value < s->t_len/2
		&& top_b->value != s->hi_b->value
		&& s->b->value != s->lo_b->value) 
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
