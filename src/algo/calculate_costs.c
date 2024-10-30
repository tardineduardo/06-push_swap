#include "../push_swap.h"


///// CALCULAR AQUI


static void	lock_nodes(t_dll *node, t_info *s, int vtfind)
{
	t_dll	*adjacent;
	int		adj_type;

	bool	next_sorted;
	bool	same_stack;

	if (s->src_name == 'a')
		adj_type = -1;
	else if (s->src_name == 'b')
		adj_type = 1;

	next_sorted = (node->next->value == node->value + adj_type);
	same_stack = (ft_dclst_find_value(s->src_stack, vtfind, offsetof(t_dll, value)));

	if (next_sorted || same_stack)
	{
		node->cost = 999;
		return ;
	}
}

static void	set_parameters(char stack, t_dll *node, t_info *s)
{
	int value_to_find;
	int llen;

	if (stack == 'a')
	{
		llen = s->a_len;
		s->dst_stack = s->b;
		s->src_stack = s->a;
		s->dst_name = 'b';
		s->src_name = 'a';
	}
	else if (stack == 'b')
	{
		llen = s->b_len;
		s->dst_stack = s->a;
		s->src_stack = s->b;
		s->dst_name = 'a';
		s->src_name = 'b';
	}
	if (node->value == 0)
		value_to_find = llen - 1;
	else
		value_to_find = node->value - 1;
	lock_nodes(node, s, value_to_find);
}

void	calculate_all_costs(t_info *s)
{
	t_dll	*trav;
	int		i;

	i = 0;
	if (s->a)
	{
		trav = s->a->next;
		while (i < s->a_len)
		{
			set_parameters('a', trav, s);
			trav = trav->next;
			i++;
		}
	}
	i = 0;
	if (s->b)
	{
		trav = s->b->next;
		while (i < s->a_len)
		{
			set_parameters('b', trav, s);
			trav = trav->next;
			i++;
		}
	}
}
