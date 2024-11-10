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

void	update_sorted_status(t_table *s)
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
