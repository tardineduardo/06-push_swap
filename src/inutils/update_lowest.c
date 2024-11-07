/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lowest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:02:28 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/06 22:10:47 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void update_lowest_node_series(t_info *s, int a_len_start, int b_len_start)
{
	if (a_len_start == 0 && s->a_len != 0)
	{
		s->cheap_in_a = s->b;
		s->cheap_in_a->cost = 0;
	}
	if (b_len_start == 0 && s->b_len != 0)
	{
		s->cheap_in_b = s->b;
		s->cheap_in_b->cost = 0;
	}
}
