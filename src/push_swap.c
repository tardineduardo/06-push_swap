/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/04 21:11:09 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int debug_movecount = 0;

int	main(int argc, char *argv[])
{
	t_info	*s;

	s = malloc(sizeof(t_info));
	ft_validate_args(argc, argv);
	ft_init_stacks(s, argc, argv);
	//	ft_play(s);
	//even_nodes_per_stack(s);
	split_by_order(s);
	find_hi_lo_nodes(s);
	
	while (1)
	{
		update_sorted_status(s);
		ft_play_print_values(&(s->a), &(s->b));
		calculate_all_costs3(s);
		ft_play_print_values(&(s->a), &(s->b));
		move(s);
		ft_play_print_values(&(s->a), &(s->b));
		swapping_works(s);
		ft_play_print_values(&(s->a), &(s->b));

		update_sorted_status(s);
		if ((s->a_csort))
			break ;
		if ((s->b_csort))
			break ;
		if (gridlock(s))
			break ;
		ft_printf("%i\n", s->debug_movecount);
}
		if (gridlock(s))
			ft_printf("GRIDLOCK\n");
		if ((s->a_csort))
			ft_printf("a sorted\n");
		if ((s->b_csort))
			ft_printf("b sorted\n");
		ft_printf("%i\n", s->debug_movecount);
	




}




	// ft_play(s);
