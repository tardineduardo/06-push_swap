#include "../../push_swap.h"

static void	node_rev_cost(t_info *s, t_dll *node, char dest_stack)
{
	int		distance_src;
	int		distance_dst;
	t_dll	*node_in_dst;


	if (dest_stack == 'b')
		node_in_dst = ft_dclst_find_node(&(s->b), node->precedent);
	else
		node_in_dst = ft_dclst_find_node(&(s->a), node->precedent);
	if (node_in_dst == NULL)
	{
		node->cost_rev = 999;
		return ;
	}
	if (dest_stack == 'b')
	{
		distance_src = ft_dclst_dist_head_unid_len(&(s->a), node, s->a_len, 'r');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->b), node->precedent, s->b_len, 'r');
	}	
	else
	{
		distance_src = ft_dclst_dist_head_unid_len(&(s->b), node, s->b_len, 'r');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->a), node->precedent->next, s->a_len, 'r');
	}
	node->cost_rev = greatest(distance_src, distance_dst) + 1;
}

void calculate_rev_costs2(t_info *s, char dest_stack)
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
					node_rev_cost(s, trav, 'b');
				else
					node_rev_cost(s, trav, 'a');
			}
			trav = trav->next;
			if (trav == s->a || trav == s->b)
				break ;
		}
	}
}
