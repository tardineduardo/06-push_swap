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


// FAZER DIREITO o SWAP. FAZER DOIS OPOSTOS JUNTOS

// SE NAO DER CERTO, DESISTE.


// static void	move_swp_a(t_info *s, t_dll *lowest)
// {
// 	int	dist_nd_head;

// 	dist_nd_head = ft_dclst_dist_head_bidi(&(s->a), lowest);
// 	if (dist_nd_head > 0)
// 		while (lowest != s->a->next)
// 			rra(s, 1);
// 	if (dist_nd_head < 0)
// 		while (lowest->pre != s->a)
// 			ra(s, 1);
// 	sa(s, 1);
// 	s->block_swap = true;
// 	return ;
// }

// static void	move_swp_b(t_info *s, t_dll *lowest)
// {
// 	int	dist_nd_head;

// 	dist_nd_head = ft_dclst_dist_head_bidi(&(s->b), lowest);
// 	if (dist_nd_head > 0)
// 		while (lowest != s->b->next)
// 			rrb(s, 1);
// 	if (dist_nd_head < 0)
// 		while (lowest->pre != s->b)
// 			rb(s, 1);
// 	sb(s, 1);
// 	s->block_swap = true;
// 	return ;	
// }

// static void move_swp(t_info *s, t_dll *lowest)
// {
// 	if (s->dst_name == 'b')
// 		move_swp_a(s, lowest);
// 	else if (s->dst_name == 'a')
// 		move_swp_b(s, lowest);
// 	return ;
// }





static void move_opo_srev_drot(t_info *s, t_dll *lowest)
{
	if (s->dst_name == 'a')
	{
		while (lowest != s->b->next)
			rrb(s, 1);
		while (lowest->to_meet != s->a)
			ra(s, 1);
		pa(s, 1);
		}
	if (s->dst_name == 'b')
	{
		while (lowest != s->a->next)
			rra(s, 1);
		while (lowest->to_meet != s->b->next)
			rb(s, 1);
		pb(s, 1);
	}
}



static void move_opo_srot_drev(t_info *s, t_dll *lowest)
{
	if (s->dst_name == 'a')
	{
		while (lowest != s->b->next)
			rb(s, 1);
		while (lowest->to_meet != s->a->next)
			rra(s, 1);
		pa(s, 1);
		}
	if (s->dst_name == 'b')
	{
		while (lowest != s->a->next)
			ra(s, 1);
		while (lowest->to_meet != s->b->next)
			rrb(s, 1);
		pb(s, 1);
	}
}

	//////////////////////////// O B ESTA CHECADO< MAS PODE TER ERRO NO A!!!!


static void move_rev(t_info *s, t_dll *lowest)
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
	if (s->b && s->dst_name == 'b')
	{
		while (lowest != s->a->next && lowest->to_meet != s->b->next)
			rrr(s, 1);
		while (lowest != s->a->next)
			rra(s, 1);
		while (lowest->to_meet != s->b->next)
			rrb(s, 1);
		pb(s, 1);
	}
}


static void move_rot(t_info *s, t_dll *lowest)
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
	if (s->dst_name == 'b')
	{
		while (lowest != s->a->next && lowest->to_meet != s->b->next)
			rr(s, 1);
		while (lowest != s->a->next)
			ra(s, 1);
		while (lowest->to_meet != s->b->next)
			rb(s, 1);
		pb(s, 1);
	}
}

void	select_move_to_execute(t_info *s, t_dll *lowest)
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

void	select_node_to_move(t_info *s)
{
	t_dll *cheap_in_a;
	t_dll *cheap_in_b;

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

	// if (cheap_in_a->cost == 999 && cheap_in_b->cost == 999)
	// 	rr(s, 1);

	return ;
}
