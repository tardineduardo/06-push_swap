/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:42:02 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/12 20:20:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_set_lowest_node_to_move(t_dll *node)
{
	int		*values;
	bool	*moves;
	int		i;
	int		lowest_i;

	values = &node->cost_rot;
	moves = &node->move_rot;
	i = 0;
	lowest_i = -1;
	while (i < 4)
	{
		if (values[i] > 0 && (lowest_i == -1 || values[i] < values[lowest_i]))
			lowest_i = i;
		i++;
	}
	if (lowest_i != -1)
		node->cost = values[lowest_i];
	i = 0;
	while (i < 4)
	{
		moves[i] = (values[i] == values[lowest_i]);
		i++;
	}
}

static void	ft_calculate_each_node_in_a(t_table *s)
{
	t_dll	*trav;
	int		i;

	i = 0;
	trav = s->a;
	while (i < s->a_len)
	{
		ft_reset_costs(s, trav);
		if (s->b)
			ft_calculate_cost_a_to_b(s, trav);
		ft_set_lowest_node_to_move(trav);
		if (trav->cost < 17 && s->mode == 'l')
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

void	ft_calculate_all_costs(t_table *s)
{
	find_hi_lo_nodes(s);
	ft_calculate_each_node_in_a(s);
	return ;
}
