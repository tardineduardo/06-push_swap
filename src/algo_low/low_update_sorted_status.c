/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_update_sorted_status.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:26:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/11 16:05:05 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	low_update_sorted_status(t_table *s)
{
	int	diff;

	s->a_is_clock_sorted = false;
	s->b_is_clock_sorted = false;
	diff = abs(s->a_len - s->b_len);
	if (diff < s->t_len / 10
		&& ft_dclst_clock_sortd(&(s->a), 'n', offsetof(t_dll, value)))
		s->a_is_clock_sorted = true;
	if (diff < s->t_len / 10
		&& ft_dclst_clock_sortd(&(s->b), 'r', offsetof(t_dll, value)))
		s->b_is_clock_sorted = true;
	return ;
}

void	low_update_partially_sorted_status(t_table *s)
{
	s->a_partially_sorted = false;
	s->b_partially_sorted = false;
	if (ft_dclst_circ_sortd(&(s->a), 'i', 'n', offsetof(t_dll, value)))
		s->a_partially_sorted = true;
	if (ft_dclst_circ_sortd(&(s->b), 'i', 'r', offsetof(t_dll, value)))
		s->b_partially_sorted = true;
	return ;
}
