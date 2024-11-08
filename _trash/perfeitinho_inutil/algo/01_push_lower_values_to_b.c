#include "../push_swap.h"

t_dll *find_position_in_a(t_info *s, t_dll *node)
{
    t_dll   *trav;
	t_dll	*high;
	t_dll	*low;
	int		tlen;

	tlen = s->t_len;
    if (s->b_len == 0 || s->b_len == 1)
        return (s->b);
    high = ft_dclst_find_highest_int(&(s->a), offsetof(t_dll, value));
    low = ft_dclst_find_lowest_int(&(s->a), offsetof(t_dll, value));
    if (node->value == s->t_len - 1)
        return (0);
	else if (node->value > high->value || node->value < low->value)
		return (high);
	trav = s->a;
	while (trav->next != s->a)
    {
		if (trav->value == 0)
		{
			if (node->value >= (s->t_len - 1) && node->value < trav->next->value) ///// TESTAR
				break ;
		}
		else if (tlen - node->value > tlen - trav->value && tlen - node->value < tlen - trav->prev->value) //// TESTAR, SO TROQUEI VALEORES
			break ;		
		trav = trav->next;
    }
    return (trav);
}


t_dll *find_position_in_b(t_info *s, t_dll *node)
{
    t_dll   *trav;
	t_dll	*high;
	t_dll	*low;
	int		tlen;

	tlen = s->t_len;
    if (s->b_len == 0 || s->b_len == 1)
        return (s->b);
    high = ft_dclst_find_highest_int(&(s->b), offsetof(t_dll, value));
    low = ft_dclst_find_lowest_int(&(s->b), offsetof(t_dll, value));
    if (node->value == 0)
        return (high);
	else if (node->value > high->value || node->value < low->value)
		return (high);
	trav = s->b;
	while (trav->next != s->b)
    {
		if (trav->value == 0)
		{
			if (node->value <= (s->t_len - 1) && node->value > trav->next->value)
				break ;
		}
		else if (tlen - node->value < tlen - trav->value && tlen - node->value > tlen - trav->prev->value)
			break ;		
		trav = trav->next;
    }
    return (trav);
}

static void calculate_costs_in_a(t_info *s)
{
	t_dll *trav;
	t_dll *position_in_b;
	int cost_a;
	int cost_b;
	int i;

	i = 0;
	trav = s->a->next;
	while (i < s->t_len)
	{
		if (trav->value > (s->t_len / 2) - 1)
			trav->cost = 999;
		else
		{
			position_in_b = find_position_in_b(s, trav);
			cost_a = abs(ft_dclst_dist_head_bidi_len(&(s->a), trav, s->a_len));
			cost_b = abs(ft_dclst_dist_head_bidi_len(&(s->b), position_in_b, s->b_len));
			trav->cost = cost_a + cost_b + 1;
		}
	i++;
	trav = trav->next;
	}
}

static void move_best_to_top(t_info *s)
{
	t_dll *lowest_cost;
	
	calculate_costs_in_a(s);
	////ft_play_print_values(&(s->a), &(s->b));
	lowest_cost = ft_dclst_find_lowest_int(&(s->a), offsetof(t_dll, cost));
	s->dst_name = 'b';
	move_node_to_top_source(s, lowest_cost);
}

bool rotate_b(t_info *s)
{
	t_dll *position_in_b;
	
	s->dst_name = 'b';
	if (s->b_len == 0 || s->b_len == 1)
		return (false);
	position_in_b = find_position_in_b(s, s->a->next);
	move_node_to_top_dest(s, position_in_b);
	return (true);
}

void push_lower_values_to_b(t_info *s)
{
	////ft_play_print_values(&(s->a), &(s->b));
	s->a_is_clock_sorted = ft_dclst_clock_sortd(&(s->a), 'n', offsetof(t_dll, value));
	if(s->a_is_clock_sorted && s->a_len >= s->t_len / 2)
		return ;

	while (s->b_len != s->t_len / 2 && !(s->a_is_clock_sorted))
	{
		if (s->a->next->value <= (s->t_len / 2) - 1)
		{
			//swapping_works(s);
			if(rotate_b(s))
				ft_play_print_values(&(s->a), &(s->b));
			pb(s, 1);
				ft_play_print_values(&(s->a), &(s->b));
		}
		else
		{
			move_best_to_top(s);
				ft_play_print_values(&(s->a), &(s->b));
		}
	}
}
