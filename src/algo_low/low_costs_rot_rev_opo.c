/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_costs_rot_rev_opo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:42:02 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/11 19:22:18 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	low_set_costs_of_moves(int dist_s_head, int dist_d_head, t_dll *node)
{
	if (dist_s_head > 0 && dist_d_head > 0)
	{
		node->move_rev = true;
		node->cost_rev = 1 + abs(dist_s_head) + abs(dist_d_head - dist_s_head);
	}
	else if (dist_s_head < 0 && dist_d_head < 0)
	{
		node->move_rot = true;
		node->cost_rot = 1 + abs(dist_s_head) + abs(dist_d_head - dist_s_head);
	}
	else if (dist_s_head <= 0 && dist_d_head >= 0)
	{
		node->move_opo_srot_drev = true;
		node->cost_opo_srot_drev = 1 + abs(dist_s_head) + abs(dist_d_head);
	}
	else if (dist_s_head >= 0 && dist_d_head <= 0)
	{
		node->move_opo_srev_drot = true;
		node->cost_opo_srev_drot = 1 + abs(dist_s_head) + abs(dist_d_head);
	}
}

void	low_calculate_cost_b_to_a(t_table *s, t_dll *node)
{
	t_dll	*trav_a;
	int		dest_a_dist;
	int		node_b_dist;

	if (s->mode == 's' && node->value > s->t_len / 2)
		return ;
	node_b_dist = ft_dclst_dist_head_bidi_len(&(s->b), node, s->b_len);
	trav_a = s->hi_a;
	if (trav_a->value < node->value)
		node->to_meet = s->hi_a->next;
	else
	{
		while (node->value < trav_a->value 
			&& node->value < trav_a->prev->value
			&& trav_a->prev != s->hi_a
			&& s->a_len != 1)
			trav_a = trav_a->prev;
		node->to_meet = trav_a;
	}
	dest_a_dist = ft_dclst_dist_head_bidi_len(&(s->a), node->to_meet, s->a_len);
	low_set_costs_of_moves(node_b_dist, dest_a_dist, node);
	return ;
}

void	low_calculate_cost_a_to_b(t_table *s, t_dll *node)
{
	t_dll	*trav_b;
	int		dest_b_dist;
	int		node_a_dist;

	if (s->mode == 's' && node->value < s->t_len / 2)
		return ;
	node_a_dist = ft_dclst_dist_head_bidi_len(&(s->a), node, s->a_len);
	trav_b = s->lo_b;
	if (trav_b->value > node->value)
		node->to_meet = s->lo_b->next;
	else
	{
		while (node->value > trav_b->value
			&& node->value > trav_b->prev->value
			&& trav_b->prev != s->lo_b
			&& s->b_len != 1)
			trav_b = trav_b->prev;
		node->to_meet = trav_b;
	}
	dest_b_dist = ft_dclst_dist_head_bidi_len(&(s->b), node->to_meet, s->b_len);
	low_set_costs_of_moves(node_a_dist, dest_b_dist, node);
	return ;
}
