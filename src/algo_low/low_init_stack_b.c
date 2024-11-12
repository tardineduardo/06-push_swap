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

static void	low_swap_closer(t_table *s)
{
	t_dll	*travf;
	t_dll	*travb;	
	int		dist_f;
	int		dist_b;

	travf = s->a->next;
	travb = s->a->next;
	find_hi_lo_nodes(s);
	while (travf->value < travf->next->value 
			&& travf != s->hi_a
			&& travf->next != s->hi_a)
		travf = travf->next;
	while (travf->value < travf->next->value 
			&& travf != s->hi_a
			&& travf->next != s->hi_a)
		travb = travb->prev;
	dist_f = ft_dclst_dist_head_bidi(&(s->a), travf);
	dist_b = ft_dclst_dist_head_bidi(&(s->a), travb);
	s->dst_name = 'a';
	if (ft_abs(dist_f) >= ft_abs(dist_b))
		ft_move_node_to_top(s, &(s->a), travb);
	else
		ft_move_node_to_top(s, &(s->a), travf);
	ft_sa(s, 1);
	return ;
}

static void	low_rotate_closer(t_table *s)
{
	t_dll	*travf;
	t_dll	*travb;	
	int		dist_f;
	int		dist_b;

	travf = s->a->next;
	travb = s->a->next;
	while (travf->value >= s->t_len / 2)
		travf = travf->next;
	while (travb->value >= s->t_len / 2)
		travb = travb->prev;
	dist_f = ft_dclst_dist_head_bidi(&(s->a), travf);
	dist_b = ft_dclst_dist_head_bidi(&(s->a), travb);
	if (ft_abs(dist_f) >= ft_abs(dist_b))
		ft_rra(s, 1);
	else
		ft_ra(s, 1);
	return ;
}

void	low_ft_init_stack_b(t_table *s)
{
	while (s->b_len < (s->t_len) / 2 && !(s->a_partially_sorted))
	{
		low_try_swapping(s);
		ft_update_partially_sorted_status(s);
		if (s->a_partially_sorted)
			break;
		if	(s->a->next->value < (s->t_len) / 2)
			ft_pb(s, 1);
		else
			low_rotate_closer(s);
	}
	ft_update_partially_sorted_status(s);
	if (s->a_partially_sorted)
		return ;
	else
		low_swap_closer(s);
	return ;
}
