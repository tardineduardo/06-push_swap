/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_move_choose_and_run.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:43:29 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/11 16:36:38 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	low_select_move_to_execute(t_table *s, t_dll *lowest)
{
	if (lowest->move_sam)
		low_move_sam(s, lowest);
	if (lowest->move_rot)
		low_move_rot(s, lowest);
	else if (lowest->move_rev)
		low_move_rev(s, lowest);
	else if (lowest->move_opo_srev_drot)
		low_move_opo_srev_drot(s, lowest);
	else if (lowest->move_opo_srot_drev)
		low_move_opo_srot_drev(s, lowest);
	return ;
}

void	low_move(t_table *s)
{
	t_dll	*cheap_in_a;
	t_dll	*cheap_in_b;

	if (!(s->cheap_a_locked))
		s->cheap_in_a = ft_dclst_find_lowest_int(&(s->a), offsetof(t_dll, cost));
	cheap_in_b = ft_dclst_find_lowest_int(&(s->b), offsetof(t_dll, cost));
	if (s->dst_name == 'a')
	{
		s->cheap_in_a = NULL;
		cheap_in_b = ft_dclst_find_lowest_int(&(s->b), offsetof(t_dll, cost));
		if (cheap_in_b)
			low_select_move_to_execute(s, cheap_in_b);
	}
	else if (s->dst_name == 'b')
	{
		cheap_in_a = s->cheap_in_a;
		cheap_in_b = NULL;
		if (cheap_in_a)
			low_select_move_to_execute(s, cheap_in_a);
	}
	return ;
}
