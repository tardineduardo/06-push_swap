void	update_node_a_cost(t_dll *node, t_table *s)
{
	t_dll	*trav;
	int		value_to_find;
	size_t	cost_a;
	size_t	cost_b;
	int		i;

	if (node->value == 0)
		value_to_find = s->a_len + s->b_len - 1;
	else
		value_to_find = node->value - 1;

	// VAL TO FIND É SEMPRE O ANTERIOR
	// LOCK IF ALREADY IN ORDER IN STACK
	if (ft_dclst_find_value(&(s->a), value_to_find, offsetof(t_dll, value)))
	{
		node->cost = 99;
		return ;
	}
	if (node->value + 1 == node->next->value)
	{
		node->cost = 99;
		return ;
	}

	cost_a = abs(ft_dclst_dist_head_bidi(&(s->a), node));
	
	if (s->b_len == 0 || s->b_len == 1)
		cost_b = 0;
	
	trav = s->b;
	i = 0;
	while (i < s->b_len)
	{
		if (value_to_find == trav->value)
		{
			cost_b = abs(ft_dclst_dist_head_bidi(&(s->b), trav));
			break ;
		}
		i++;
		trav = trav->next;
	}
	node->cost = cost_a + cost_b + 1;
}

void	update_node_b_cost(t_dll *node, t_table *s)
{
	t_dll	*trav;
	int		value_to_find;
	size_t	cost_a;
	size_t	cost_b;
	int		i;
	// VAL TO FIND É SEMPRE O ANTERIOR
	if (node->value == 0)
		value_to_find = s->a_len + s->b_len - 1;
	else
		value_to_find = node->value - 1;

	if (ft_dclst_find_value(&(s->b), value_to_find, offsetof(t_dll, value)))
	{
		node->cost = 99;
		return ;
	}
	if (node->value - 1 == node->next->value)
	{
		node->cost = 99;
		return ;
	}

	cost_b = abs(ft_dclst_dist_head_bidi(&(s->b), node));
	
	if (s->a_len == 0 || s->a_len == 1)
		cost_b = 0;
	
	trav = s->a;
	i = 0;
	while (i < s->a_len)
	{
		if (value_to_find == trav->value)
		{
			cost_a = abs(ft_dclst_dist_head_bidi(&(s->a), trav));
			break ;
		}
		i++;
		trav = trav->next;
	}
	node->cost = cost_a + cost_b + 1;
}

void	calculate_all_costs(t_table *s)
{
	t_dll	*trav;
	int		i;

	i = 0;
	if (s->a)
	{
		trav = s->a->next;
		while (i < s->a_len)
		{
			update_node_a_cost(trav, s);
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
			update_node_b_cost(trav, s);
			trav = trav->next;
			i++;
		}
	}
}