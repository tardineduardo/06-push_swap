/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:42:02 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/06 16:26:21 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void set_costs_to_locked(t_dll *node) /// mover para INUTILS
{
	node->cost_rev = 999;
	node->cost_rev = 999;;
	node->cost_opo_srot_drev = 999;;
	node->cost_opo_srev_drot =  999;;
}



static void reset_costs(t_dll *node) /// mover para INUTILS
{
	node->cost_rev = 998;
	node->cost_rev = 998;;
	node->cost_opo_srot_drev = 998;;
	node->cost_opo_srev_drot =  998;;
}



static void set_dist_and_move_type(int dist_src_to_head, int dist_dst_to_head, t_dll *node)
{
	reset_costs(node); // MODE A LEVEL UP IF ADDING SWAP.

	if (dist_src_to_head > 0 && dist_src_to_head > 0)
	{
		node->move_rev = true;
		node->cost_rev = 1 + abs(dist_src_to_head - dist_dst_to_head);
	}
	if (dist_src_to_head < 0 && dist_src_to_head < 0)
	{
		node->move_rot = true;
		node->cost_rev = 1 + abs(dist_src_to_head - dist_dst_to_head);
	}
	if (dist_src_to_head < 0 && dist_src_to_head > 0)
	{
		node->move_opo_srot_drev = true;
		node->cost_opo_srot_drev = 1 + abs(dist_src_to_head) + abs(dist_dst_to_head);
	}
	if (dist_src_to_head > 0 && dist_src_to_head < 0)
	{
		node->move_opo_srev_drot = true;
		node->cost_opo_srev_drot =  1 + abs(dist_src_to_head) + abs(dist_dst_to_head);
	}
}

//FROM B TO A
static void	calculate_move_b_to_a(t_info *s, t_dll *node)
{
	t_dll *trav_a;
	int dest_a_dist;
	int node_b_dist;

	if (node->value < (s->t_len / 2) || s->b_len < 3)    // eu deveria mesmo checar se o tamanho é minimo?
	{
		set_costs_to_locked(node);
		return ;
	}
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

////////////////  PAREI AQUI ///////////////////////////////////////////////////






// COST FROM A->B
static void	calculate_move_a_to_b(t_info *s, t_dll *node)
{
	t_dll *trav_b;
	int dest_b_dist;
	int node_a_dist;

	if (node->value >= (s->t_len / 2) || s->b_len < 3)
	{
		set_costs_to_locked(node);
		return ;
	}
	node_a_dist = ft_dclst_dist_head_bidi(&(s->a), node);
	trav_b = s->lo_b;
	if (trav_b->value > node->value)
		node->to_meet = s->lo_b;
	else
	{
		while (node->value > trav_b->prev->value && trav_b->prev->value < s->t_len /2 && trav_b->next != s->hi_b)
			trav_b = trav_b->prev;
		node->to_meet = trav_b;
	}
	dest_b_dist = ft_dclst_dist_head_bidi(&(s->b), node->to_meet);
	set_dist_and_move_type(node_a_dist, dest_b_dist, node);
	return ;
}

static void	reset_costs(t_info *s)
{
	t_dll *trav;
	int		i;
	if (s->a)
	{
		i = 0;
		trav = s->a;
		while (i < s->a_len)
		{
			trav->cost = 998;
			trav = trav->next;
			i++;
		}
	}
	if (s->b)
	{
		i = 0;
		trav = s->b;
		while (i < s->b_len)
		{
			trav->cost = 998;
			trav = trav->next;
			i++;
		}
	}
}


static void	calculate_each_node(t_info *s)
{
	t_dll *trav;
	int		i;
	if (s->a)
	{
		i = 0;
		trav = s->a;
		while (i < s->a_len)
		{
			//reset_costs(node); // MODE A LEVEL UP IF ADDING SWAP.
			calculate_move_a_to_b(s, trav);
			trav = trav->next;
			i++;
		}
	}
	if (s->b)
	{
		i = 0;
		trav = s->b;
		while (i < s->b_len)
		{
			//reset_costs(node); // MODE A LEVEL UP IF ADDING SWAP.
			calculate_move_b_to_a(s, trav);
			trav = trav->next;
			i++;
		}
	}
}

void	calculate_all_costs(t_info *s)
{

	find_hi_lo_nodes(s);
	reset_costs(s);
	calculate_each_node(s);



}





// static void	calculate_b(t_info *s, t_dll *node)
// {
// 	t_dll *top_b = s->b->next;

// 	if (top_b->value < s->t_len / 2)
// 		s->b->next->cost = 999;
// 	else if (s->b_len < 3)
// 		s->b->next->cost = 999;
// 	else if (s->b_len < 3)
// 		s->b->next->cost = 999;
// 	else
// 	{
// 		t_dll *trav;

// 		trav = s->hi_a;
// 		if (trav->value < top_b->value)
// 		{
// 			s->b->next->cost = ft_dclst_dist_head_bidi(&(s->a), s->hi_a->next);
// 			s->a_to_move = s->hi_a->next;
// 		}
// 		else
// 		{                 								
// 			while (top_b->value < trav->value && top_b->value < trav->prev->value && trav->prev->value != s->hi_a->value)
// 				trav = trav->prev;
// 			s->b->next->cost = ft_dclst_dist_head_bidi(&(s->a), trav);
// 			s->a_to_move = trav;

// 		}
// 	}
// }