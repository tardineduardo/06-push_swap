/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:44:52 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/28 21:12:40 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	solve(t_info *s)
{
	//ft_printf(BLUE "\n\nINICIO\n" RESET);
	//ft_play_print_values(&(s->a), &(s->b));

	s->a_is_csortd = ft_dclst_circ_sortd(&(s->a), 'i', 'i', offsetof(t_dll, value));
	s->b_is_csortd = ft_dclst_circ_sortd(&(s->b), 'i', 'o', offsetof(t_dll, value));
	while ((!s->a_is_csortd || !s->b_is_csortd) && (s->a_len >= s->a_len/2) && (s->b_len >= s->b_len/2) )
	{
		ft_printf("%i\n", s->debug_movecount);
//		ft_play_print_values(&(s->a), &(s->b));
		if (swapping_works(s))
			break ;

		calculate_all_costs(s);		
		find_lowest_cost(s);
		move_cheapest_node(s);
		
		//ft_play_print_values(&(s->a), &(s->b));
		calculate_all_costs(s);
		s->a_is_csortd = ft_dclst_circ_sortd(&(s->a), 'i', 'i', offsetof(t_dll, value));
		s->b_is_csortd = ft_dclst_circ_sortd(&(s->b), 'i', 'o', offsetof(t_dll, value));
	}
	//ft_play_print_values(&(s->a), &(s->b));

}
