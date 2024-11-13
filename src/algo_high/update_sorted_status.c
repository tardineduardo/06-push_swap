/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sorted_status.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:33:08 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/13 16:33:10 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_update_partially_sorted_status(t_table *s)
{
	s->a_partially_sorted = false;
	if (ft_dclst_circ_sortd(&(s->a), 'n', offsetof(t_dll, value)))
		s->a_partially_sorted = true;
	return ;
}
