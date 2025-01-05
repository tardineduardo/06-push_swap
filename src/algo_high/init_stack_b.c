/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:43:29 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/18 15:48:47 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push_two_values(t_table *s)
{
	bool	is_low;
	bool	is_high;

	is_low = false;
	is_high = false;
	while (s->b_len < 2)
	{
		if (!is_low && s->a->next->value <= s->limit_low)
		{
			ft_pb(s, 1);
			is_low = true;
		}
		else if (!is_high && s->a->next->value >= s->limit_high)
		{
			ft_pb(s, 1);
			is_high = true;
		}
		else
			ft_ra(s, 1);
	}
}

void	ft_init_stack_b(t_table *s)
{
	ft_update_partially_sorted_status(s);
	if (s->a_partially_sorted)
	{
		s->already_sorted = true;
		return ;
	}
	ft_push_two_values(s);
	if (s->b->next->value < s->b->next->next->value)
		ft_sb(s, 1);
}
