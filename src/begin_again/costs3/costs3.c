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
	if (s->a->next->value >= 0 && s->a->next->value < (s->t_len/2))
	{
		s->a->next->cost = 999;
	}
	else
	{
		t_dll *trav;

		trav = s->lo_b;
		if (trav->value > s->a->next->value)
		{
			s->a->next->cost = ft_dclst_dist_head_bidi(&(s->b), s->lo_b->next);
			s->b_to_move = s->lo_b->next;
		}
		else
		{
			while (trav->next->value < s->a->next->value && trav->next->value > s->lo_b->value)
				trav = trav->next;
			s->a->next->cost = ft_dclst_dist_head_bidi(&(s->b), s->lo_b);
			s->b_to_move = s->lo_b;
		}
	}

	///// 	// FROM B -> A

	if (s->b->next->value >= s->t_len / 2 && s->b->next->value <= s->t_len - 1)
		s->b->next->cost = 999;
	else
	{
		t_dll *trav;

		trav = s->hi_a;
		if (trav->value < s->b->next->value)
		{
			////s->hi_a = s->b->next; FAZER SO SE MUDAR
			s->b->next->cost = ft_dclst_dist_head_bidi(&(s->a), s->hi_a->next);
			s->a_to_move = s->hi_a->next;
		}
		else
		{
			while (trav->next->value > s->a->next->value && trav->next->value < s->lo_a->value)
				trav = trav->next;
			s->b->next->cost = ft_dclst_dist_head_bidi(&(s->a), s->hi_a->next);
			s->a_to_move = s->hi_a->next;

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

	// REVER O MELHOR MOMENTO DE CALCULAR ISSO
	s->hi_a = ft_dclst_find_highest_int(&(s->a), offsetof(t_dll, value));
	s->hi_b = ft_dclst_find_highest_int(&(s->b), offsetof(t_dll, value));

	reset_costs3(s);
	calculate_cost3(s);
}


