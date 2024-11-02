/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/01 22:26:15 by eduribei         ###   ########.fr       */
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
//	ft_play_print_values(&(s->a), &(s->b));
	//	ft_play(s);
	even_nodes_per_stack(s);
//	ft_play_print_values(&(s->a), &(s->b));
	calculate_all_costs(s);
	update_sorted_status(s);
	while (1)
	{
		update_sorted_status(s);
		calculate_all_costs(s);
//		ft_play_print_values(&(s->a), &(s->b));
		make_move(s);
		calculate_all_costs(s);
//		ft_play_print_values(&(s->a), &(s->b));
		update_sorted_status(s);
		if ((s->a_csort || s->b_csort))
			break ;
		if (all_locked(s))
			even_nodes_per_stack(s);
	}


	update_sorted_status(s);
	calculate_all_costs(s);
	ft_play_print_values(&(s->a), &(s->b));
	ft_printf("%i\n", s->debug_movecount);
	}




	// ft_play(s);
