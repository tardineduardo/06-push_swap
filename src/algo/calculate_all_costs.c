#include "../push_swap.h"
void	opo_cost(t_info *s, t_dll *node, char dest_stack)
{
	t_dll	*node_in_dst;
	int		cost1;
	int		cost2;
	int		distance_src;
	int		distance_dst;

	if (dest_stack == 'b')
		node_in_dst = ft_dclst_find_node(&(s->b), node->adjacent);
	else if (dest_stack == 'a')
		node_in_dst = ft_dclst_find_node(&(s->a), node->adjacent);
	if (node_in_dst == NULL)
	{
		node->cost_opo = 999;
		return ;
	}
	if (dest_stack == 'b')
	{
		distance_src = ft_dclst_dist_head_unid_len(&(s->a), node, s->a_len, 'r');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->b), node->adjacent, s->b_len, 'f');
		cost1 = distance_src + distance_dst;
		distance_src = ft_dclst_dist_head_unid_len(&(s->a), node, s->a_len, 'f');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->b), node->adjacent, s->b_len, 'r');
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
		distance_dst = ft_dclst_dist_head_unid_len(&(s->a), node->adjacent->next, s->a_len, 'f');
		cost1 = distance_src + distance_dst;
		distance_src = ft_dclst_dist_head_unid_len(&(s->b), node, s->b_len, 'f');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->a), node->adjacent->next, s->a_len, 'r');
		cost2 = distance_src + distance_dst;
		node->cost_opo = lowest(cost1, cost2) + 1;
		if (cost1 < cost2)
			node->opo_way_a = 'f';
		else
			node->opo_way_a = 'r';		
	}
}

void calculate_opo_costs(t_info *s)
{
	t_dll	*trav;
	int		i;
	if (s->a)
	{
		i = 0;
		trav = s->a;
		while (i < s->a_len)
		{
			if (trav->cost != 999)
				opo_cost(s, trav, 'b');
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
			if (trav->cost != 999)
				opo_cost(s, trav, 'a');
			trav = trav->next;
			i++;
		}
	}
}

void	rev_cost(t_info *s, t_dll *node, char dest_stack)
{
	int		distance_src;
	int		distance_dst;
	t_dll	*node_in_dst;


	if (dest_stack == 'b')
		node_in_dst = ft_dclst_find_node(&(s->b), node->adjacent);
	else if (dest_stack == 'a')
		node_in_dst = ft_dclst_find_node(&(s->a), node->adjacent);
	if (node_in_dst == NULL)
	{
		node->cost_rev = 999;
		return ;
	}
	if (dest_stack == 'b')
	{
		distance_src = ft_dclst_dist_head_unid_len(&(s->a), node, s->a_len, 'r');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->b), node->adjacent, s->b_len, 'r');
	}	
	else if (dest_stack == 'a')
	{
		distance_src = ft_dclst_dist_head_unid_len(&(s->b), node, s->b_len, 'r');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->a), node->adjacent->next, s->a_len, 'r');
	}
	node->cost_rev = greatest(distance_src, distance_dst) + 1;
}

void calculate_rev_costs(t_info *s)
{
	t_dll	*trav;
	int		i;
	if (s->a)
	{
		i = 0;
		trav = s->a;
		while (i < s->a_len)
		{
			if (trav->cost != 999)
				rev_cost(s, trav, 'b');
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
			if (trav->cost != 999)
				rev_cost(s, trav, 'a');
			trav = trav->next;
			i++;
		}
	}
}


void	rot_cost(t_info *s, t_dll *node, char dest_stack)
{
	int		distance_src;
	int		distance_dst;
	t_dll	*node_in_dst;

	if (dest_stack == 'b')
		node_in_dst = ft_dclst_find_node(&(s->b), node->adjacent);
	else if (dest_stack == 'a')
		node_in_dst = ft_dclst_find_node(&(s->a), node->adjacent);
	if (node_in_dst == NULL)
	{
		node->cost_rot = 999;
		return ;
	}
	if (dest_stack == 'b')
	{
		distance_src = ft_dclst_dist_head_unid_len(&(s->a), node, s->a_len, 'f');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->b), node->adjacent, s->b_len, 'f');
		node->cost_rot = greatest(distance_src, distance_dst) + 1;
	}	
	else if (dest_stack == 'a')
	{
		distance_src = ft_dclst_dist_head_unid_len(&(s->b), node, s->b_len, 'f');
		distance_dst = ft_dclst_dist_head_unid_len(&(s->a), node->adjacent->next, s->a_len, 'f'); ////
		node->cost_rot = greatest(distance_src, distance_dst) + 1;
	}
}

void calculate_rot_costs(t_info *s)
{
	t_dll	*trav;
	int		i;
	if (s->a)
	{
		i = 0;
		trav = s->a;
		while (i < s->a_len)
		{
			if (trav->cost != 999)
				rot_cost(s, trav, 'b');
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
			if (trav->cost != 999)
				rot_cost(s, trav, 'a');
			trav = trav->next;
			i++;
		}
	}
}

void	lock_all_stack(t_dll **tail)
{
	t_dll *trav;

	trav = *tail;
	while (1)
	{
		trav->cost = 999;
		trav = trav->next;
		if (trav == *tail)
			break ;
	}
}


static void	lock_sorted_nodes(t_info *s)
{
	t_dll	*trav;
	int		i;
	
	i = 0;
	if (s->a)
	{
		if(s->a_len <= s->t_len / 4)
			lock_all_stack(&(s->a));
		else	
		{
			trav = s->a->next;
			while (i < s->a_len)
			{
				if (trav->prev == trav->adjacent || trav == s->last_moved)
					trav->cost = 999;
				trav = trav->next;
				i++;
			}
		}
	}
	if (s->b)
	{
		if(s->b_len <= s->t_len / 3)
			lock_all_stack(&(s->b));
		else
		{
			i = 0;
			trav = s->b->next;
			while (i < s->b_len)
			{
				if (trav->next == trav->adjacent || trav == s->last_moved)
					trav->cost = 999;
				trav = trav->next;
				i++;
			}
		}
	}
}

void find(t_dll *node)
{
	int		*values;
	bool	*moves;
	int		i;
	int		lowest_i;

	if(node->cost == 999)
		return ;
	values = (int *)((char *)node + offsetof(t_dll, cost_rot));
	moves = (bool *)((char *)node + offsetof(t_dll, move_rot));
	i = 0;
	lowest_i = i;
	while (i < 2)  // Loop through the three values: values[0], values[1], values[2]
	{
		if (values[i + 1] < values[i] && values[i] != 998)
			lowest_i = i + 1;
		i++;
	}
	node->cost = values[lowest_i];
	i = 0;
	if(node->cost == 999)
		return ;	
	while(i < 3)
	{
		if (values[i] == values[lowest_i])
			moves[i] = true;
		i++;	
	}
}

void	find_lowest_and_set_move(t_info *s)
{
	t_dll *trav;
	int		i;
	if (s->a)
	{
		i = 0;
		trav = s->a;
		while (i < s->a_len)
		{
			find(trav);
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
			find(trav);
			trav = trav->next;
			i++;
		}
	}
}

void	reset_costs(t_info *s)
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
			trav->cost_rev = 998;
			trav->cost_rot = 998;
			trav->cost_opo = 998;
			trav->move_rot = false;
			trav->move_rev = false;
			trav->move_opo = false;
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
			trav->cost_rev = 998;
			trav->cost_rot = 998;
			trav->cost_opo = 998;
			trav->move_rot = false;
			trav->move_rev = false;
			trav->move_opo = false;			
			trav = trav->next;
			i++;
		}
	}
}


void	calculate_all_costs(t_info *s)
{
	reset_costs(s);
	lock_sorted_nodes(s);
	calculate_rot_costs(s);
	calculate_rev_costs(s);
	calculate_opo_costs(s);
	find_lowest_and_set_move(s);
}


//////////////////// AS CONTAS DE B------>A não estão batendo. tem algum erro. 