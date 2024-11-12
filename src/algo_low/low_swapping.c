/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_swapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:08:06 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/12 20:20:16 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_low_try_swapping(t_table *s)
{
	if (s->a && s->a->next->value > s->a->next->next->value)
		ft_sa(s, 1);
	return ;
}
