#include "../../push_swap.h"

void	lock_all_stack2(t_dll **tail)
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

static void	lock_sorted_nodes2(t_info *s)
{
	t_dll	*trav;
	int		i;
	
	i = 0;
	if (s->a)
	{
		if(s->a_len <= s->t_len / 3 || s->a_csort)
			lock_all_stack2(&(s->a));
		else	
		{
			trav = s->a->next;
			while (i < s->a_len)
			{
				if (trav->prev == trav->pre || trav == s->last_moved)
					trav->cost = 999;
				trav = trav->next;
				i++;
			}
		}
	}
	if (s->b)
	{
		if(s->b_len <= s->t_len / 3 || s->b_csort)
			lock_all_stack2(&(s->b));
		else
		{
			i = 0;
			trav = s->b->next;
			while (i < s->b_len)
			{
				if (trav->next == trav->pre || trav == s->last_moved)
					trav->cost = 999;
				trav = trav->next;
				i++;
			}
		}
	}
}

void	find2(t_dll *node)
{
	int		*values;
	bool	*moves;
	int		i;
	int		lowest_i;

	if(node->cost == 999)
		return ;
	values = (int *)((char *)node + offsetof(t_dll, cost_sam));
	moves = (bool *)((char *)node + offsetof(t_dll, move_sam));
	i = 0;
	lowest_i = i;
	while (i < 4)  // Loop through the three values: values[0], values[1], values[2]
	{
		if (values[i + 1] < values[i] && values[i] != 998)
			lowest_i = i + 1;
		i++;
	}
	node->cost = values[lowest_i];
	i = 0;
	if (node->cost == 999)
		return ;	
	while(i < 5)
	{
		if (values[i] == values[lowest_i])
			moves[i] = true;
		i++;	
	}
}

void	find_lowest_and_set_move2(t_info *s)
{
	t_dll *trav;
	int		i;
	if (s->a)
	{
		i = 0;
		trav = s->a;
		while (i < s->a_len)
		{
			find2(trav);
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
			find2(trav);
			trav = trav->next;
			i++;
		}
	}
}

void	reset_costs2(t_info *s)
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
			trav->cost_sam = 998;
			trav->cost_swp = 998;
			trav->move_rot = false;
			trav->move_rev = false;
			trav->move_opo = false;
			trav->move_sam = false;
			trav->move_swp = false;						
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
			trav->cost_sam = 998;
			trav->cost_swp = 998;
			trav->move_rot = false;
			trav->move_rev = false;
			trav->move_opo = false;
			trav->move_sam = false;
			trav->move_swp = false;					
			trav = trav->next;
			i++;
		}
	}
}

void	calculate_all_costs2(t_info *s)
{
	reset_costs2(s);
	lock_sorted_nodes2(s);
	calculate_rot_costs2(s, 'a');
	calculate_rev_costs2(s, 'a');
	calculate_opo_costs2(s, 'a');
	calculate_sam_costs2(s, 'a');
	calculate_swp_costs2(s, 'a');
	calculate_rot_costs2(s, 'b');
	calculate_rev_costs2(s, 'b');
	calculate_opo_costs2(s, 'b');
	calculate_sam_costs2(s, 'b');
	calculate_swp_costs2(s, 'b');
	find_lowest_and_set_move2(s);
	return ;
}


