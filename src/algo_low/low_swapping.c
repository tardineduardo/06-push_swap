/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_swapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:08:06 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/11 20:19:08 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	low_swapping_works(t_table *s)
{
	bool swap_a;
	bool swap_b;

	swap_a = false;
	swap_b = false;
	if (s->a != NULL)
		if (s->a->next->value > s->a->next->next->value)
			//&& s->a->next->value > s->t_len / 2
			//&& s->a->next->next->value > s->t_len / 2
			//&& s->a->next != s->hi_a)
			swap_a = true;
	if (s->b != NULL)
		if (s->b->next->value < s->b->next->next->value
			&& s->b->next->value < s->t_len / 2
			&& s->b->next->next->value < s->t_len / 2
			&& s->b->next != s->lo_b)
			swap_b = true;
	if (!swap_a && !swap_b)
		return (false);
	else if (swap_a && swap_b)
		ss(s, 1);
	else if (swap_a)
		sa(s, 1);
	else if (swap_b)
		sb(s, 1);
	return (true);
}
