/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:42:02 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/10 20:10:32 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_lowest_node_to_move(t_table *s, t_dll *node, char stack)
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

static void	calculate_each_node_in_a(t_table *s)
{
	t_dll	*trav;
	int		i;

	i = 0;
	trav = s->a;
	while (i < s->a_len)
	{
		ft_reset_costs(s, trav);
		if (s->b)
			calculate_cost_a_to_b(s, trav);
		set_lowest_node_to_move(s, trav, 'a');
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

static void	calculate_each_node_in_b(t_table *s)
{
	t_dll	*trav;
	int		i;

	i = 0;
	trav = s->b;
	while (i < s->b_len)
	{
		ft_reset_costs(s, trav);
		if (s->a)
			calculate_cost_b_to_a(s, trav);
		set_lowest_node_to_move(s, trav, 'b');
		//if (trav->cost < 5)
		// {
		// 	s->cheap_in_a = trav;
		// 	s->cheap_a_locked = true;
		// 	break ;
		// }
		trav = trav->next;
		i++;
	}
	return ;
}

//find_hi_lo_nodes: TENTAR ELIMINAR ESSA CONTAGEM A CADA VOLTA.
void	calculate_all_costs(t_table *s)
{
	find_hi_lo_nodes(s);
	if (s->dst_name == 'b')
		calculate_each_node_in_a(s);
	if (s->dst_name == 'a')
		calculate_each_node_in_b(s);
	return ;
}
