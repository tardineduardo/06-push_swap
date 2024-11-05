/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:42:02 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/04 20:40:14 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	calculate_cost3(t_info *s)
{
	// COST A->B
	if (s->a->next->value > s->t_len/2 - 1)
		s->a->next->cost = 999;
	else if (s->a_len < 3)
		s->a->next->cost = 999;	
	else if (s->a_csort)
		s->b->next->cost = 999;		
	else
	{
		t_dll *trav;

		trav = s->lo_b;
		if (trav->value > s->a->next->value)
		{
			s->a->next->cost = ft_dclst_dist_head_bidi(&(s->b), s->lo_b);
			s->b_to_move = s->lo_b;
		}
		else
		{
			while (s->a->next->value > trav->prev->value && trav->prev->value < s->t_len /2 && trav->next != s->hi_b)
				trav = trav->prev;
			s->a->next->cost = ft_dclst_dist_head_bidi(&(s->b), trav);
			s->b_to_move = trav;
		}
	}

	///// 	COST FROM B -> A
	t_dll *topb = s->b->next;

	if (topb->value < s->t_len / 2)
		s->b->next->cost = 999;
	else if (s->b_len < 3)
		s->b->next->cost = 999;
	else if (s->b_len < 3)
		s->b->next->cost = 999;
	else
	{
		t_dll *trav;

		trav = s->hi_a;
		if (trav->value < topb->value)
		{
			s->b->next->cost = ft_dclst_dist_head_bidi(&(s->a), s->hi_a->next);
			s->a_to_move = s->hi_a->next;
		}
		else
		{                 								
			while (topb->value < trav->value && topb->value < trav->prev->value && trav->prev->value != s->hi_a->value)
				trav = trav->prev;
			s->b->next->cost = ft_dclst_dist_head_bidi(&(s->a), trav);
			s->a_to_move = trav;

		}
	}
}




static void	reset_costs3(t_info *s)
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
			trav = trav->next;
			i++;
		}
	}
}

void	calculate_all_costs3(t_info *s)
{

	find_hi_lo_nodes(s);

	reset_costs3(s);
	calculate_cost3(s);



}


