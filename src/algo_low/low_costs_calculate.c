/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_costs_calculate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:42:02 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/11 19:30:26 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	low_set_lowest_node_to_move(t_table *s, t_dll *node, char stack)
{
	int		*values;
	bool	*moves;
	int		i;
	int		lowest_i;

	values = &node->cost_sam;
	moves = &node->move_sam;
	i = 0;
	lowest_i = i;
	while (i < 4)
	{
		if (values[i + 1] < values[i])
			lowest_i = i + 1;
		i++;
	}
	node->cost = values[lowest_i];
	i = 0;
	if (node->cost == 999 || node->cost == 998)
		return ;
	while (i < 5)
	{
		if (values[i] == values[lowest_i])
			moves[i] = true;
		i++;
	}
}

static void	low_calculate_each_node_in_a(t_table *s)
{
	t_dll	*trav;
	int		i;

	i = 0;
	trav = s->a;
	while (i < s->a_len)
	{
		low_ft_reset_costs(s, trav);
		if (s->b)
			low_calculate_cost_a_to_b(s, trav);
		low_calculate_sam_costs2(s, 'a');
		low_set_lowest_node_to_move(s, trav, 'a');
		if (trav->cost < 25 && s->mode == 'l')
		{
			s->cheap_in_a = trav;
			s->cheap_a_locked = true;
			break ;
		}
		trav = trav->next;
		i++;
	}
	return ;
}

static void	low_calculate_each_node_in_b(t_table *s)
{
	t_dll	*trav;
	int		i;

	i = 0;
	trav = s->b;
	while (i < s->b_len)
	{
		low_ft_reset_costs(s, trav);
		if (s->a)
			low_calculate_cost_b_to_a(s, trav);
		low_calculate_sam_costs2(s, 'b');
		low_set_lowest_node_to_move(s, trav, 'b');
		trav = trav->next;
		i++;
	}
	return ;
}

void	low_calculate_all_costs(t_table *s)
{
	if (s->mode == 's')
	{
		low_find_hi_lo_nodes(s);
		low_calculate_each_node_in_a(s);
		low_calculate_each_node_in_b(s);
	}
	if (s->mode == 'm' || s->mode == 'l')
	{
		s->dst_name = 'b';
		low_find_hi_lo_nodes(s);
		low_calculate_each_node_in_a(s);
	}
	return ;
}
//
//	