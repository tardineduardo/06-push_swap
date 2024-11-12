#include "../../push_swap.h"

static void	node_swp_cost(t_dll **tail, t_dll *node, char stack)
{
	int		dist_nd_head;
	int		flag;

	flag = 0;
	if(ft_dclst_find_node(tail, node->precedent) == NULL)
		flag = 1;
	if (stack == 'a' && node->next == node->procedent)
		flag = 1;
	if (stack == 'a' && node->prev == node->precedent)
	 	flag = 1;
	if (stack == 'a' && node->prev == node->prev->prev->procedent)
		flag = 1;
	if (stack == 'a' && node->next != node->precedent)
		flag = 1;
	if (stack == 'b' && node->prev == node->precedent)	
		flag = 1;
	if (stack == 'b' && node->next == node->procedent)
		flag = 1;
	if (stack == 'b' && node->prev == node->prev->prev->precedent)
		flag = 1;
	if (stack == 'b' && node->prev != node->precedent)
		flag = 1;		
	if (flag)
	{
		node->cost_swp = 999;
		return;
	}
	if (stack == 'a')
	{
		node->cost_swp = abs(ft_dclst_dist_head_bidi(tail, node)) + 1;
	}
	if (stack == 'b')
		node->cost_swp = abs(ft_dclst_dist_head_bidi(tail, node->precedent)) + 1;
	return;
}

void calculate_swp_costs2(t_table *s, char stack)
{
	t_dll	*trav;

	if (stack == 'a')
		trav = s->a;
	else
		trav = s->b;
	if (trav)
	{
		while (1)
		{
			if (trav->cost != 999)
			{
				if (stack == 'b')
					node_swp_cost(&(s->b), trav, 'b');
				else
					node_swp_cost(&(s->a), trav, 'a');
			}
			trav = trav->next;
			if (trav == s->a || trav == s->b)
				break ;
		}
	}
	return ;
}
