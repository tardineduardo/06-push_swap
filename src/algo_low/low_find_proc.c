/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_find_pre_and_pro.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:36:46 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/11 16:03:51 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	low_assign_procedent_node(t_table *s)
{
	t_dll *trav_a;
	t_dll *trav_b;
	int	a;
	int b;
	
	a = 0;
	trav_a = s->a;
	trav_b = s->a->prev;
	while (a < s->a_len)
	{
		b = 0;
		while (b < s->a_len)
		{
			if (trav_a->value != s->a_len - 1)
			{
				if (trav_a->value == trav_b->value - 1)
					trav_a->procedent = trav_b;
				b++;
				trav_b = trav_b->prev;
			}
			else
			{
				if (trav_b->value == 0)
					trav_a->procedent = trav_b;
				b++;
				trav_b = trav_b->prev;	
			}
		}
		trav_a = trav_a->prev;
		a++;
	}
}
