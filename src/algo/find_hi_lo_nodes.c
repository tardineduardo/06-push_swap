/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hi_lo_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:21:59 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/04 19:37:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void find_hi_lo_nodes(t_table *s)
{
//	s->hi_a = ft_dclst_find_highest_int(&(s->a), offsetof(t_dll, value));
//	s->hi_b = ft_dclst_find_highest_int(&(s->b), offsetof(t_dll, value));
	s->lo_a = ft_dclst_find_lowest_int(&(s->a), offsetof(t_dll, value));
	s->lo_b = ft_dclst_find_lowest_int(&(s->b), offsetof(t_dll, value));

	return ;
}