#include "../push_swap.h"


static void	reposition_b(t_info *s, t_dll *node)
{
	t_dll *precedent;

	precedent = ft_dclst_find_value(&(s->b), (node->value) - 1, offsetof(t_dll, value));
	move_node_to_top_dest(s, precedent);
}

static void	reposition_a(t_info *s, t_dll *node)
{
	t_dll *precedent;

	precedent = ft_dclst_find_value(&(s->a), node->value - 1, offsetof(t_dll, value));
	precedent = precedent->next;
	move_node_to_top_dest(s, precedent);
}

void	repostion_dst_s(t_info *s, t_dll *node)
{
	if(s->dst_name == 'a')
		reposition_a(s, node);
	else if (s->dst_name == 'b')
		reposition_b(s, node);	
}
