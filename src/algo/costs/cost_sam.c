#include "../../push_swap.h"

static void	node_sam_cost(t_dll **tail, t_dll *node, char stack)
{
	int	dist_nd_head;
	int dist_pr_head;

	if(ft_dclst_find_node(tail, node->pre) == NULL)
	{
		node->cost_sam = 999;
		return;
	}
	dist_nd_head = ft_dclst_dist_head_bidi(tail, node);
	if (stack == 'a')
		dist_pr_head = ft_dclst_dist_head_bidi(tail, node->pre->next);
	else
		dist_pr_head = ft_dclst_dist_head_bidi(tail, node->pre);
	node->cost_sam = abs(dist_nd_head) + abs(dist_pr_head - dist_nd_head) + 2;
	return;
}

void calculate_sam_costs2(t_info *s, char stack)
{
	t_dll	*trav;
	int		i;

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
					node_sam_cost(&(s->b), trav, 'b');
				else
					node_sam_cost(&(s->a), trav, 'a');
			}
			trav = trav->next;
			if (trav == s->a || trav == s->b)
				break ;
		}
	}
}
