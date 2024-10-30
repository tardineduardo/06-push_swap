#include "../push_swap.h"

t_dll *find_lowest(t_dll **tail, int llen)
{
	t_dll	*trav;
	t_dll	*lowest_node;
	size_t		total;
	int 	i;

	if (!tail || !(*tail))
		return (NULL);
	trav = (*tail)->next;
	lowest_node = trav;
	i = 0;
	while(i < llen)
	{	
		total = lowest_node->value + lowest_node->cost;
		if (trav->cost <= lowest_node->cost && total < trav->value + trav->cost)
			lowest_node = trav;
		trav = trav->next;
		if ((*tail)->next == NULL)
			ft_error_exit("List not circular. Check list structure.\n", 1);
	}
	return (lowest_node);
}


void	find_lowest_cost(t_info *s)
{
	t_dll *cheaper_a;
	t_dll *cheaper_b;

	cheaper_a = ft_dclst_find_lowest_int(&(s->a), offsetof(t_dll, cost));
	cheaper_b = ft_dclst_find_lowest_int(&(s->b), offsetof(t_dll, cost));

	if (cheaper_a->cost < cheaper_b->cost || s->a_len > s->b_len)
	{
		s->cheapest_node = cheaper_a;
		s->cheapest_stack = s->a;
		s->dst_stack = s->b;
		s->dst_name = 'b';
	}
	else if (cheaper_a->cost > cheaper_b->cost || s->a_len <= s->b_len)
	{
		s->cheapest_node = cheaper_b;
		s->cheapest_stack = s->b;
		s->dst_stack = s->a;
		s->dst_name = 'a';
	}
}
