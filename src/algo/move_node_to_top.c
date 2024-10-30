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

void	move_node_b_to_top(t_info *s, t_dll *node)
{
	int distance;

	distance = ft_dclst_dist_from_head(&(s->b), node);
	if (distance >= 0)
	{
		while (distance > 0)
		{
			rb(s, 1);
			distance--;
		}
	}
	else if (distance < 0)
	{
		while (distance < 0)
		{
			rrb(s, 1);
			distance++;
		}
	}
}

void	move_node_a_to_top(t_info *s, t_dll *node)
{
	int distance;

	distance = ft_dclst_dist_from_head(&(s->a), node);
	if (distance >= 0)
	{
		while (distance > 0)
		{
			ra(s, 1);
			distance--;
		}
	}
	else if (distance < 0)
	{
		while (distance < 0)
		{
			rra(s, 1);
			distance++;
		}
	}
}

void	move_node_to_top_source(t_info *s, t_dll *node)
{
	if (s->dst_name == 'b')
		move_node_a_to_top(s, node);
	else if (s->dst_name == 'a')
		move_node_b_to_top(s, node);
	else
		ft_error_exit("move_nod_to_top: invalid stack.\n", 1);
}

void	move_node_to_top_dest(t_info *s, t_dll *node)
{
	if (s->dst_name == 'b')
		move_node_b_to_top(s, node);
	else if (s->dst_name == 'a')
		move_node_a_to_top(s, node);
	else
		ft_error_exit("move_nod_to_top: invalid stack.\n", 1);
}