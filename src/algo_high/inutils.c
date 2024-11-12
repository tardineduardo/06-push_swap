/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/12 17:26:55 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reset_costs(t_table *s, t_dll *node)
{
	node->cost = -1;
	node->cost_rot = -1;
	node->cost_rev = -1;
	node->cost_opo_srot_drev = -1;
	node->cost_opo_srev_drot = -1;
	node->move_rot = false;
	node->move_rev = false;
	node->move_opo_srev_drot = false;
	node->move_opo_srot_drev = false;
	s->cheap_a_locked = false;
	s->cheap_in_a = NULL;
}
