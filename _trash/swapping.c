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

bool	swapping_works(t_table *s)
{
	bool swap_a;
	bool swap_b;

	swap_a = false;
	swap_b = false;

	if (s->a != NULL)
		if ((s->a->next->next->pre == s->a || s->a->pre == s->a->next->next))
			swap_a = true;
	if (s->b != NULL)
		if ((s->b)->next->value == (s->b)->next->next->value - 1)
			swap_b = true;
	if (!swap_a && !swap_b)
		return (false);
	else if (swap_a && swap_b)
		ss(s, 1);
	else if (swap_a)
		sa(s, 1);
	else if (swap_b)
		sb(s, 1);
	//update_sorted_status(s);
	return (true);
}