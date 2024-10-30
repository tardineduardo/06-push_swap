#include "../push_swap.h"

/* */
static void	calculate(t_dll *node, t_info *s, int vtfind)
{
	int		s_r_cost;
	int		s_rr_cost;
	int		d_r_cost;
	int		d_rr_cost;
	t_dll	*adjacent;



	adjacent = ft_dclst_find_value(&(s->dst_stack), vtfind, offsetof(t_dll, value));
	s_r_cost = ft_dclst_dist_head_unid(&(s->src_stack), node, 'f');
	s_rr_cost = ft_dclst_dist_head_unid(&(s->src_stack), node, 'r');
	d_r_cost = ft_dclst_dist_head_unid(&(s->dst_stack), adjacent, 'f');
	d_rr_cost = ft_dclst_dist_head_unid(&(s->dst_stack), adjacent, 'r');

	if (abs(s_r_cost - d_r_cost) > abs(s_rr_cost - d_rr_cost))
		node->cost = greatest(s_rr_cost, d_rr_cost) * -1;
	else
		node->cost = greatest(s_r_cost, d_r_cost);
	///// ESTA BUGADO AQUI.

}

/* checks if a node shouldn't move in this round. 1) it's predecessor is the same stack. 2) it's next value
is sorted for that stack (b is reverse).*/
static void	lock_nodes(t_dll *node, t_info *s, int vtfind)
{
	ft_play_print_values(&(s->a), &(s->b));
	t_dll	*adjacent;
	int		adj_type;

	bool	next_sorted;
	bool	same_stack;

	if (s->src_name == 'a')
		adj_type = 1;
	else
		adj_type = -1;

	adjacent = ft_dclst_find_value(&(s->src_stack), vtfind, offsetof(t_dll, value));

	next_sorted = (node->next->value == node->value + adj_type);
	same_stack = adjacent;

	if (next_sorted || same_stack)
	{
		node->cost = 999;
		return ;
	}
	calculate(node, s, vtfind);

}

/* sets what value needs to be found and which stacks are source and destination. */
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

/* calculates the cost of moving each node in both stacks */
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
