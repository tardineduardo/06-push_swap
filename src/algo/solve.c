/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:44:52 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/28 20:39:44 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


bool	swapping_works(t_dll **t_a, t_dll **t_b)
{
	bool swap_a;
	bool swap_b;

	swap_a = false;
	swap_b = false;

	if (*t_a != NULL)
		if (((t_nd *)((*t_a)->next->content))->val > ((t_nd *)((*t_a)->next->next->content))->val)
			swap_a = true;
	if (*t_b != NULL)
		if (((t_nd *)((*t_b)->next->content))->val < ((t_nd *)((*t_b)->next->next->content))->val)
		swap_b = true;
	if (!swap_a && !swap_b)
		return (false);
	if (swap_a && swap_b)
		ss(t_a, t_b, 1);
	else if (swap_a)
		sa(t_a, 1);
	else if (swap_b)
		sb(t_b, 1);
	return (true);
}

void	update_node_a_cost(t_dll *node, t_dll **t_a, t_dll **t_b)
{
	t_dll	*trav;
	int		value;
	size_t	cost_a;
	size_t	cost_b;
	int		llen_b;
	int		i;

	llen_b = ft_dclstsize(t_b);
	value = ((t_nd *)(node->content))->val;
	if (ft_dclsttrav_to_value(t_a, value - 1, 'n', offsetof(t_nd, val)))
	{
		((t_nd *)(node->content))->cost = 0;
		return ;
	}
	cost_a = abs(ft_dclst_dist_from_head(t_a, node));
	if (llen_b == 0 || llen_b == 1)
		cost_b = 0;
	trav = *t_b;
	i = 0;
	while (i < llen_b)
	{
		if (value - 1 == ((t_nd *)((*t_b)->content))->val)
			cost_b = abs(ft_dclst_dist_from_head(t_b, node));
		i++;
	}
	((t_nd *)(node->content))->cost = cost_a + cost_b + 1;
}


void	update_node_b_cost(t_dll *node, t_dll **t_a, t_dll **t_b)
{
	t_dll	*trav;
	int		value;
	size_t	cost_a;
	size_t	cost_b;
	int		llen_a;
	int		i;

	llen_a = ft_dclstsize(t_a);
	value = ((t_nd *)(node->content))->val;
	if (ft_dclsttrav_to_value(t_b, value - 1, 'n', offsetof(t_nd, val)))
	{
		((t_nd *)(node->content))->cost = 0;
		return ;
	}
	cost_b = abs(ft_dclst_dist_from_head(t_b, node));
	if (llen_a == 0 || llen_a == 1)
		cost_b = 0;
	trav = *t_a;
	i = 0;
	while (i < llen_a)
	{
		if (value + 1 == ((t_nd *)((*t_a)->content))->val)
			cost_a = abs(ft_dclst_dist_from_head(t_a, node));
		i++;
	}
	((t_nd *)(node->content))->cost = cost_a + cost_b + 1;
}

void	calculate_all_costs(t_dll **t_a, t_dll **t_b)
{
	t_dll	*trav;
	int		llen_a;
	int		llen_b;	
	int		i;
	
	llen_a = ft_dclstsize(t_a);
	i = 0;
	trav = (*t_a)->next;
	while (i < llen_a)
	{
		update_node_a_cost(trav, t_a, t_b);
		trav = trav->next;
		i++;
	}
	llen_b = ft_dclstsize(t_b);
	i = 0;
	trav = (*t_b)->next;
	while (i < llen_b)
	{
		update_node_b_cost(trav, t_a, t_b);
		trav = trav->next;
		i++;
	}
}

void	solve(t_dll **t_a, t_dll **t_b)
{
	bool	a_is_csorted;
	bool	b_is_csorted;

	//ft_printf("INICIO\n");
	//ft_play_print(t_a, t_b);
	ft_debug_print_dclist(t_a, "int", offsetof(t_nd, label), 1);
	ft_debug_print_dclist(t_a, "int", offsetof(t_nd, val), 1);


	a_is_csorted = false;
	b_is_csorted = true;
	//while (!(a_is_csorted && b_is_csorted))
	int a = 0;
	pb(t_a, t_b, 1);

	while (a < 2)
	{
		if (!(swapping_works(t_a, t_b)))
		{
			calculate_all_costs(t_a, t_b);
			ft_play_print(t_a, t_b);
		}
		a_is_csorted = ft_dclst_circ_sortd(t_a, "int", 'n', offsetof(t_nd, val));
		b_is_csorted = ft_dclst_circ_sortd(t_b, "int", 'r', offsetof(t_nd, val));
		ft_printf("a, val and cost");
		ft_debug_print_dclist(t_a, "int", offsetof(t_nd, val), 1);
		ft_debug_print_dclist(t_a, "int", offsetof(t_nd, cost), 1);
		ft_printf("b, val and cost");
		ft_debug_print_dclist(t_b, "int", offsetof(t_nd, val), 1);
		ft_debug_print_dclist(t_b, "int", offsetof(t_nd, cost), 1);
		
		break ;
	}




}
