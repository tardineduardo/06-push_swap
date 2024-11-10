/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:43:29 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 16:22:46 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	select_move_to_execute(t_table *s, t_dll *lowest)
{
	if (lowest->move_rot)
		move_rot(s, lowest);
	else if (lowest->move_rev)
		move_rev(s, lowest);
	else if (lowest->move_opo_srev_drot)
		move_opo_srev_drot(s, lowest);
	else if (lowest->move_opo_srot_drev)
		move_opo_srot_drev(s, lowest);
	return ;
}

void	move(t_table *s)
{
	t_dll	*cheap_in_a;
	t_dll	*cheap_in_b;

	cheap_in_a = ft_dclst_find_lowest_int(&(s->a), offsetof(t_dll, cost));
	cheap_in_b = ft_dclst_find_lowest_int(&(s->b), offsetof(t_dll, cost));
	if (s->dst_name == 'a')
	{
		cheap_in_a = NULL;
		cheap_in_b = ft_dclst_find_lowest_int(&(s->b), offsetof(t_dll, cost));
		if (cheap_in_b)
			select_move_to_execute(s, cheap_in_b);
	}
	else if (s->dst_name == 'b')
	{
		cheap_in_a = ft_dclst_find_lowest_int(&(s->a), offsetof(t_dll, cost));
		cheap_in_b = NULL;
		if (cheap_in_a)
			select_move_to_execute(s, cheap_in_a);
	}
	return ;
}
