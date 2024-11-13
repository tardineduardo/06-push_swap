/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hi_lo_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:30:40 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/13 16:30:42 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_hi_lo_nodes(t_table *s)
{
	s->hi_a = ft_dclst_find_hi_int(&(s->a), offsetof(t_dll, value));
	s->hi_b = ft_dclst_find_hi_int(&(s->b), offsetof(t_dll, value));
	s->lo_a = ft_dclst_find_lo_int(&(s->a), offsetof(t_dll, value));
	s->lo_b = ft_dclst_find_lo_int(&(s->b), offsetof(t_dll, value));
	return ;
}
