/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 17:52:05 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void debug_status(t_info *s)
{
	//// ////ft_play_print_values(&(s->a), &(s->b));
	if (gridlock(s))
	 	ft_printf("GRIDLOCK\n");
	if ((s->a_is_clock_sorted))
		ft_printf("a sorted\n");
	if ((s->b_is_clock_sorted))
		ft_printf("b sorted\n");
	ft_printf("%i\n", s->debug_movecount);
}


int	main(int argc, char *argv[])
{
	t_info	*s;

	s = malloc(sizeof(t_info));
	ft_validate_args(argc, argv);
	ft_init_stack_a(s, argc, argv);
	send_two_lower_values_to_stack_b(s);
	find_hi_lo_nodes(s);
	s->dst_name = 'b';
	while (1)
	{
		//ft_play_print_values(&(s->a), &(s->b));
		calculate_all_costs(s);
		//ft_play_print_values(&(s->a), &(s->b));
		select_node_to_move(s);
		update_sorted_status(s);
		if (s->b_len == (s->t_len))
			break ;
	}
	//ft_play_print_values(&(s->a), &(s->b));	
	move_node_to_top(s, &(s->b), s->hi_b);
	//ft_play_print_values(&(s->a), &(s->b));	
	while (s->b_len)
	{
		pa(s, 1);
		//ft_play_print_values(&(s->a), &(s->b));
	}
	debug_status(s);


	// s->dst_name = 'a';
	// while(1)
	// {
	// 	calculate_all_costs(s);
	// 	//ft_play_print_values(&(s->a), &(s->b));		
	// 	select_node_to_move(s);
	// 	mid_sorted_status(s);
	// }

}


	////ft_play_print_values(&(s->a), &(s->b));


	// ft_play(s);
	//split_by_alternate_order(s);



		// if (gridlock(s))
		// {
	 	// 	ft_printf("GRIDLOCK...");
		// 	break ;	
		// }
	//	ft_play(s);

			// 	if (swapping_works(s))
			// {
			// 	// ////ft_play_print_values(&(s->a), &(s->b));
			// 	continue;
			// }
			// else if (swapping_back_works(s))
			// {
			// 	////ft_play_print_values(&(s->a), &(s->b));
			// 	continue;
			// }
			// else
			// 	rr(s, 1);	









