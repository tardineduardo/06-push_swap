/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node_to_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:26:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 19:23:37 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_node_to_top(t_dll **stack, t_dll *node)
{
	int distance;
	
	distance = ft_dclst_dist_from_head(stack, node);
	if (distance >= 0)
	{
		while (distance > 0)
		{
			ra(stack, 1);
			distance--;
		}
	}
	else if (distance < 0)
	{
		while (distance < 0)
		{
			rra(stack, 1);
			distance++;
		}
	}
}