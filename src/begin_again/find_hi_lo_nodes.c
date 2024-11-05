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

void find_hi_lo_nodes(t_info *s)
{
	t_dll	*low;

	s->hi_a = ft_dclst_find_value(&(s->a), s->t_len - 1, offsetof(t_dll, value));
	s->lo_b = ft_dclst_find_lowest_int(&(s->b), offsetof(t_dll, value));

	s->lo_a = ft_dclst_find_value(&(s->a), s->t_len / 2, offsetof(t_dll, value));
//	s->ideal_lo_b = 0;


	return ;
}