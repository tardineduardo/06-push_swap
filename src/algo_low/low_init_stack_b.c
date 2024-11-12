/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_init_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:43:29 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/11 22:20:29 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	low_ft_init_stack_b(t_table *s)
{
	PRINT;
	while (s->b_len < (s->t_len) / 2 && !(s->a_partially_sorted))
	{
		low_swapping_works(s); PRINT;
		low_update_partially_sorted_status(s);
		if (s->a_partially_sorted)
			break;
		if	(s->a->next->value < (s->t_len) / 2)
			pb(s, 1);
		else
			ra(s, 1);
		PRINT;	
	}
	if (s->a_partially_sorted)
		return ;
	else
	{
		while (!(s->a_partially_sorted))
		{
			low_swapping_works(s); PRINT;
			ra(s, 1);
			low_update_partially_sorted_status(s);
		}	
	}
	return ;
}
