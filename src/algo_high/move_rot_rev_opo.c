/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rot_rev_opo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:26:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 17:51:05 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_move_opo_srev_drot(t_table *s, t_dll *lowest)
{
	while (lowest != s->a->next)
		ft_rra(s, 1);
	while (lowest->to_meet != s->b->next)
		ft_rb(s, 1);
	ft_pb(s, 1);
}

void	ft_move_opo_srot_drev(t_table *s, t_dll *lowest)
{
	while (lowest != s->a->next)
		ft_ra(s, 1);
	while (lowest->to_meet != s->b->next)
		ft_rrb(s, 1);
	ft_pb(s, 1);
	return ;
}

void	ft_move_rev(t_table *s, t_dll *lowest)
{
	while (lowest != s->a->next && lowest->to_meet != s->b->next)
		ft_rrr(s, 1);
	while (lowest != s->a->next)
		ft_rra(s, 1);
	while (lowest->to_meet != s->b->next)
		ft_rrb(s, 1);
	ft_pb(s, 1);
	return ;
}

void	ft_move_rot(t_table *s, t_dll *lowest)
{
	while (lowest != s->a->next && lowest->to_meet != s->b->next)
		ft_rr(s, 1);
	while (lowest != s->a->next)
		ft_ra(s, 1);
	while (lowest->to_meet != s->b->next)
		ft_rb(s, 1);
	ft_pb(s, 1);
	return ;
}
