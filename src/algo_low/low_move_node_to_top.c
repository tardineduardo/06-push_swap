/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_move_node_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:26:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/11 16:04:31 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	low_move_node_to_top(t_table *s, t_dll **stack, t_dll *node)
{
	int	distance;

	distance = ft_dclst_dist_head_bidi(stack, node);
	if (distance >= 0)
	{
		while (distance > 0)
		{
			if (s->dst_name == 'a')
				rra(s, 1);
			if (s->dst_name == 'b')
				rrb(s, 1);	
			distance--;
		}
	}
	else if (distance < 0)
	{
		while (distance < 0)
		{
			if (s->dst_name == 'a')
				ra(s, 1);
			if (s->dst_name == 'b')
				rb(s, 1);	
			distance++;
		}
	}
}
