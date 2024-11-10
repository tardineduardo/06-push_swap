/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 15:38:57 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_costs(t_table *s, t_dll *node)
{
	node->cost = 998;
	node->cost_rot = 998;
	node->cost_rev = 998;
	node->cost_opo_srot_drev = 998;
	node->cost_opo_srev_drot = 998;
	node->move_rot = false;
	node->move_rev = false;
	node->move_opo_srev_drot = false;
	node->move_opo_srot_drev = false;
	s->cheap_a_locked = false;
	s->cheap_in_a = NULL;
}
