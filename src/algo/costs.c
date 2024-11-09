/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:42:02 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 17:30:33 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void set_cross_costs_to_locked(t_dll *node) /// mover para INUTILS
{
	node->cost = 999;
	node->cost_rot = 999;
	node->cost_rev = 999;;
	node->cost_opo_srot_drev = 999;
	node->cost_opo_srev_drot =  999;
	node->move_rot = false;
	node->move_rev = false;
	node->move_opo_srev_drot = false;
	node->move_opo_srot_drev = false;	
}

static void reset_costs(t_dll *node) /// mover para INUTILS
{
	//node->cost_swp = 998;
	node->cost = 998;
	node->cost_rot = 998;
	node->cost_rev = 998;;
	node->cost_opo_srot_drev = 998;
	node->cost_opo_srev_drot =  998;
	node->move_rot = false;
	node->move_rev = false;
	node->move_opo_srev_drot = false;
	node->move_opo_srot_drev = false;
}

static void set_dist_and_move_type(int dist_src_to_head, int dist_dst_to_head, t_dll *node)
{
	if (dist_src_to_head > 0 && dist_dst_to_head > 0)
	{
		node->move_rev = true;
		node->cost_rev = 1 + abs(dist_src_to_head) + abs(dist_dst_to_head - dist_src_to_head);
	}
	else if (dist_src_to_head < 0 && dist_dst_to_head < 0)
	{
		node->move_rot = true;
		node->cost_rot = 1 + abs(dist_src_to_head) + abs(dist_dst_to_head - dist_src_to_head);
	}
	else if (dist_src_to_head <= 0 && dist_dst_to_head >= 0)
	{
		node->move_opo_srot_drev = true;
		node->cost_opo_srot_drev = 1 + abs(dist_src_to_head) + abs(dist_dst_to_head);
	}
	else if (dist_src_to_head >= 0 && dist_dst_to_head <= 0)
	{
		node->move_opo_srev_drot = true;
		node->cost_opo_srev_drot =  1 + abs(dist_src_to_head) + abs(dist_dst_to_head);
	}
}

static void	calculate_move_b_to_a(t_table *s, t_dll *node)
{
	t_dll *trav_a;
	int dest_a_dist;
	int node_b_dist;

	node_b_dist = ft_dclst_dist_head_bidi(&(s->b), node);
	trav_a = s->hi_a;
	if (trav_a->value < node->value)
		node->to_meet = s->hi_a->next;
	else
	{                 								
		while (node->value < trav_a->value && node->value < trav_a->prev->value 
		&& trav_a->prev->value != s->hi_a->value)
			trav_a = trav_a->prev;
		node->to_meet = trav_a;
	}
	dest_a_dist = ft_dclst_dist_head_bidi(&(s->a), node->to_meet);
	set_dist_and_move_type(node_b_dist, dest_a_dist, node);
	return ;
}

static void	calculate_move_a_to_b(t_table *s, t_dll *node)
{
	t_dll *trav_b;
	int dest_b_dist;
	int node_a_dist;

	node_a_dist = ft_dclst_dist_head_bidi(&(s->a), node);
	trav_b = s->lo_b;
	if (trav_b->value > node->value)
	{
		//s->lo_b = trav_b; VERIFICAR ESSA CONTAGEM
		node->to_meet = s->lo_b->next;
	}
	else
	{
		while (node->value > trav_b->value 
		&& node->value >  trav_b->prev->value
		&& trav_b->prev != s->lo_b
		&& s->b_len != 1)
			trav_b = trav_b->prev;
		node->to_meet = trav_b;
	}
	dest_b_dist = ft_dclst_dist_head_bidi(&(s->b), node->to_meet);
	set_dist_and_move_type(node_a_dist, dest_b_dist, node);
	return ;
}

void	set_lowest_node_to_move(t_table *s, t_dll *node, char stack)
{
	int		*values;
	bool	*moves;
	int		i;
	int		lowest_i;

	if(node->cost == 999)
		return ;
	values = &node->cost_rot;
	moves = &node->move_rot;
	i = 0;
	lowest_i = i;
	while (i < 3)
	{
		if (values[i + 1] < values[i]) /// TIREI O CHECK se era != 998
			lowest_i = i + 1;
		i++;
	}
	node->cost = values[lowest_i];
	i = 0;
	if (node->cost == 999)
		return ;	
	while(i < 4)
	{
		if (values[i] == values[lowest_i])
			moves[i] = true;
		i++;
	}
}

static void	calculate_each_node(t_table *s)
{
	t_dll *trav;
	int		i;

	if (s->dst_name == 'b')
	{
		i = 0;
		trav = s->a;
		while (i < s->a_len)
		{
			reset_costs(trav);
			if (s->b)
				calculate_move_a_to_b(s, trav);
			set_lowest_node_to_move(s, trav, 'a');
			trav = trav->next;
			i++;
		}
	}
	if (s->dst_name == 'a')
	{
		i = 0;
		trav = s->b;
		while (i < s->b_len)
		{
			reset_costs(trav);
			if (s->a)
				calculate_move_b_to_a(s, trav);
			set_lowest_node_to_move(s, trav, 'b');
			trav = trav->next;
			i++;
		}
	}
	return ;
}

void	calculate_all_costs(t_table *s)
{
	find_hi_lo_nodes(s);  //TENTAR ELIMINAR ESSA CONTAGEM A CADA VOLTA, O VALOR DEVE SER ATUALIZADO SÓ QUANDO NECESSÁRIO.
	calculate_each_node(s);
	return ;
}

