/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:42:02 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 19:30:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	calculate_move_b_to_a(t_table *s, t_dll *node)
{
	t_dll	*trav_a;
	int		dest_a_dist;
	int		node_b_dist;

	node_b_dist = ft_dclst_dist_head_bidi(&(s->b), node);
	trav_a = s->hi_a;
	if (trav_a->value < node->value)
		node->to_meet = s->hi_a->next;
	else
	{
		while (node->value < trav_a->value
			&& node->value < trav_a->prev->value
			&& trav_a->prev->value != s->hi_a->value)
			trav_a = trav_a->prev;
		node->to_meet = trav_a;
	}
	dest_a_dist = ft_dclst_dist_head_bidi(&(s->a), node->to_meet);
	ft_set_cost_and_move(node_b_dist, dest_a_dist, node);
	return ;
}

static void	calculate_move_a_to_b(t_table *s, t_dll *node)
{
	t_dll	*trav_b;
	int		dest_b_dist;
	int		node_a_dist;

	node_a_dist = ft_dclst_dist_head_bidi(&(s->a), node);
	trav_b = s->lo_b;
	if (trav_b->value > node->value)
		node->to_meet = s->lo_b->next;
	else
	{
		while (node->value > trav_b->value
			&& node->value > trav_b->prev->value
			&& trav_b->prev != s->lo_b
			&& s->b_len != 1)
			trav_b = trav_b->prev; // ESSAS CONDIÇOES NAO FORAM CHECADAS COMO AS DE A
		node->to_meet = trav_b;
	}
	dest_b_dist = ft_dclst_dist_head_bidi(&(s->b), node->to_meet);
	ft_set_cost_and_move(node_a_dist, dest_b_dist, node);
	return ;
}

static void	set_lowest_node_to_move(t_dll *node)
{
	int		*values;
	bool	*moves;
	int		i;
	int		lowest_i;

	values = &node->cost_rot;
	moves = &node->move_rot;
	i = 0;
	lowest_i = i;
	while (i < 3)
	{
		if (values[i + 1] < values[i])
			lowest_i = i + 1;
		i++;
	}
	node->cost = values[lowest_i];
	i = 0;
	if (node->cost == 999)
		return ;
	while (i < 4)
	{
		if (values[i] == values[lowest_i])
			moves[i] = true;
		i++;
	}
}

void	calculate_costs_in_stack_a(t_table *s)
{
	t_dll	*trav;
	int		i;

	i = 0;
	trav = s->a;
	while (i < s->a_len)
	{
		reset_costs(trav);
		if (s->b)
			calculate_move_a_to_b(s, trav);
		set_lowest_node_to_move(trav);
		trav = trav->next;
		i++;
	}
	return ;
}

void	calculate_costs_in_stack_b(t_table *s)
{
	t_dll	*trav;
	int		i;

	i = 0;
	trav = s->b;
	while (i < s->b_len)
	{
		reset_costs(trav);
		if (s->a)
			calculate_move_b_to_a(s, trav);
		set_lowest_node_to_move(trav);
		trav = trav->next;
		i++;
	}
	return ;
}
