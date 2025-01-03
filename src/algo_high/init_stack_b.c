/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:43:29 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/12 19:52:16 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_init_stack_b(t_table *s)
{
	ft_update_partially_sorted_status(s);
	if (s->a_partially_sorted)
	{
		s->already_sorted = true;
		return ;
	}
	while (s->b_len < 2)
	{
		if (s->a->next->value > s->t_len / 2)
			ft_ra(s, 1);
		else
			ft_pb(s, 1);
	}
	return ;
}
