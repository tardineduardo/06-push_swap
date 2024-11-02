/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/01 20:55:40 by eduribei         ###   ########.fr       */
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
	ft_play_print_values(&(s->a), &(s->b));
	//	ft_play(s);
	even_nodes_per_stack(s);
	ft_play_print_values(&(s->a), &(s->b));
	calculate_all_costs(s);
	update_sorted_status(s);
	while (1)
	{
		update_sorted_status(s);
		calculate_all_costs(s);
		ft_play_print_values(&(s->a), &(s->b));
		make_move(s);
		calculate_all_costs(s);
		ft_play_print_values(&(s->a), &(s->b));
		update_sorted_status(s);
		if ((s->a_csort || s->b_csort))
			break ;
		//check_blocking_conditions
	}



	update_sorted_status(s);
	calculate_all_costs(s);
	ft_play_print_values(&(s->a), &(s->b));
	ft_printf("%i\n", s->debug_movecount);
}

// && ((s->b_len >= s->t_len /2) && (s->a_len > s->t_len /2))



	// ft_play(s);
