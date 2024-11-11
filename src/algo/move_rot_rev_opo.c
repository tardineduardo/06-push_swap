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

void	move_opo_srev_drot(t_table *s, t_dll *lowest)
{
	if (s->dst_name == 'a')
	{
		while (lowest != s->b->next)
			rrb(s, 1);
		while (lowest->to_meet != s->a)
			ra(s, 1);
		pa(s, 1);
	}
	else if (s->dst_name == 'b')
	{
		while (lowest != s->a->next)
			rra(s, 1);
		while (lowest->to_meet != s->b->next)
			rb(s, 1);
		pb(s, 1);
	}
}

void	move_opo_srot_drev(t_table *s, t_dll *lowest)
{
	if (s->dst_name == 'a')
	{
		while (lowest != s->b->next)
			rb(s, 1);
		while (lowest->to_meet != s->a->next)
			rra(s, 1);
		pa(s, 1);
	}
	else if (s->dst_name == 'b')
	{
		while (lowest != s->a->next)
			ra(s, 1);
		while (lowest->to_meet != s->b->next)
			rrb(s, 1);
		pb(s, 1);
	}
	return ;
}

void	move_rev(t_table *s, t_dll *lowest)
{
	if (s->a && s->dst_name == 'a')
	{
		while (lowest != s->b->next && lowest->to_meet != s->a)
			rrr(s, 1);
		while (lowest != s->b->next)
			rrb(s, 1);
		while (lowest->to_meet != s->a)
			rra(s, 1);
		pa(s, 1);
	}
	else if (s->b && s->dst_name == 'b')
	{
		while (lowest != s->a->next && lowest->to_meet != s->b->next)
			rrr(s, 1);
		while (lowest != s->a->next)
			rra(s, 1);
		while (lowest->to_meet != s->b->next)
			rrb(s, 1);
		pb(s, 1);
	}
	return ;
}

void	move_rot(t_table *s, t_dll *lowest)
{
	if (s->dst_name == 'a')
	{
		while (lowest != s->b->next && lowest->to_meet != s->a)
			rr(s, 1);
		while (lowest != s->b->next)
			rb(s, 1);
		while (lowest->to_meet != s->a)
			ra(s, 1);
		pa(s, 1);
	}
	else if (s->dst_name == 'b')
	{
		while (lowest != s->a->next && lowest->to_meet != s->b->next)
			rr(s, 1);
		while (lowest != s->a->next)
			ra(s, 1);
		while (lowest->to_meet != s->b->next)
			rb(s, 1);
		pb(s, 1);
	}
	return ;
}
