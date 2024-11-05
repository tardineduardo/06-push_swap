/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:08:06 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/04 16:33:28 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	swapping_works(t_info *s)
{
	bool swap_a;
	bool swap_b;

	swap_a = false;
	swap_b = false;

	if (s->a != NULL && !(s->a_csort))
		if ((s->a)->next->value > (s->a)->next->next->value && (s->a)->next->value >= s->t_len/2 && (s->a)->next->next->value >= s->t_len/2)
			swap_a = true;
	if (s->b != NULL && !(s->b_csort))
		if ((s->b)->next->value < (s->b)->next->next->value && (s->b)->next->value < s->t_len/2 && (s->b)->next->next->value < s->t_len/2)
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

	swap_a = false;
	swap_b = false;

	if (s->a != NULL && !(s->a_csort))
		if ((s->a)->value > (s->a)->next->value && (s->a)->value != s->hi_a->value &&
		(s->a)->value >= s->t_len/2 && (s->a)->next->value >= s->t_len/2 && s->a->next->value != s->a->next->next->value - 1)
			swap_a = true;
	if (s->b != NULL && !(s->b_csort))
		if ((s->b)->value < (s->b)->next->value && (s->b)->value != s->lo_b->value &&
		(s->b)->value < s->t_len/2 && (s->b)->next->value < s->t_len/2 && s->b->next->value != s->a->next->next->value + 1)
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
