/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_choose_and_run.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:43:29 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/12 18:26:18 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_move(t_table *s)
{
	if (!(s->cheap_a_locked))
		s->cheap_in_a = ft_dclst_find_lo_int(&(s->a), offsetof(t_dll, cost));
	if (s->cheap_in_a->move_rot)
		ft_move_rot(s, s->cheap_in_a);
	else if (s->cheap_in_a->move_rev)
		ft_move_rev(s, s->cheap_in_a);
	else if (s->cheap_in_a->move_opo_srev_drot)
		ft_move_opo_srev_drot(s, s->cheap_in_a);
	else if (s->cheap_in_a->move_opo_srot_drev)
		ft_move_opo_srot_drev(s, s->cheap_in_a);
	return ;
}
