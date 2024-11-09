#include "../../push_swap.h"

void	node_opo_cost(t_table *s, t_dll *node, char dest_stack)
{
	t_dll	*node_in_dst;
	int		cost1;
	int		cost2;
	int		distance_src;
	int		distance_dst;

	if (dest_stack == 'b')
		node_in_dst = ft_dclst_find_node(&(s->b), node->pre);
	else
		node_in_dst = ft_dclst_find_node(&(s->a), node->pre);
	if (node_in_dst == NULL)
	{
		node->cost_opo = 999;
		return ;
	}
	if (dest_stack == 'b')
	{
		distance_src = ft_dclst_dist_head_unid_len(&(s->a), node, s->a_len, 'r');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->b), node->pre, s->b_len, 'f');
		cost1 = distance_src + distance_dst;
		distance_src = ft_dclst_dist_head_unid_len(&(s->a), node, s->a_len, 'f');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->b), node->pre, s->b_len, 'r');
		cost2 = distance_src + distance_dst;
		node->cost_opo = lowest(cost1, cost2) + 1;
		if (cost1 < cost2)
			node->opo_way_a = 'r';
		else
			node->opo_way_a = 'f';
	}	
	else if (dest_stack == 'a')
	{
		distance_src = ft_dclst_dist_head_unid_len(&(s->b), node, s->b_len, 'r');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->a), node->pre->next, s->a_len, 'f');
		cost1 = distance_src + distance_dst;
		distance_src = ft_dclst_dist_head_unid_len(&(s->b), node, s->b_len, 'f');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->a), node->pre->next, s->a_len, 'r');
		cost2 = distance_src + distance_dst;
		node->cost_opo = lowest(cost1, cost2) + 1;
		if (cost1 < cost2)
			node->opo_way_a = 'f';
		else
			node->opo_way_a = 'r';		
	}
}

void calculate_opo_costs2(t_table *s, char dest_stack)
{
	t_dll	*trav;
	int		i;

	if (dest_stack == 'b')
		trav = s->a;
	else
		trav = s->b;
	if (trav)
	{
		while (1)
		{
			if (trav->cost != 999)
			{
				if (dest_stack == 'b')
					node_opo_cost(s, trav, 'b');
				else
					node_opo_cost(s, trav, 'a');
			}
			trav = trav->next;
			if (trav == s->a || trav == s->b)
				break ;
		}
	}
}
