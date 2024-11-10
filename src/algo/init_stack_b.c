/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:43:29 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 16:22:46 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_init_stack_b(t_table *s)
{
	while (s->b_len < 1)
	{
		if (s->a->next->value > s->t_len / 2)
			ra(s, 1);
		else
			pb(s, 1);
	}
	return ;
}
