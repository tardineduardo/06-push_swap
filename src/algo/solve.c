/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:44:52 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/30 18:46:00 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	solve(t_info *s)
{
	pb(s, 1);pb(s, 1);pb(s, 1);
	s->a_is_csortd = ft_dclst_circ_sortd(&(s->a), 'i', 'i', offsetof(t_dll, value));
	s->b_is_csortd = ft_dclst_circ_sortd(&(s->b), 'i', 'o', offsetof(t_dll, value));
	while (1)
	{
		ft_printf("%i\n", s->debug_movecount);
		// if (swapping_works(s))
		// 	break ;

		calculate_all_costs(s);
		ft_printf("%i\n", s->debug_movecount);
	
		s->a_is_csortd = ft_dclst_circ_sortd(&(s->a), 'i', 'i', offsetof(t_dll, value));
		s->b_is_csortd = ft_dclst_circ_sortd(&(s->b), 'i', 'o', offsetof(t_dll, value));
	}

}
