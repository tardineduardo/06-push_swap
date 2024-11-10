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

int	main(int argc, char *argv[])
{
	t_table	*s;

	s = malloc(sizeof(t_table));
	ft_validate_args(argc, argv);
	ft_init_stacks_and_table(s, argc, argv);
//	ft_play_print_values(&(s->a), &(s->b));
	ft_init_stack_b(s);
//	ft_play_print_values(&(s->a), &(s->b));
	find_hi_lo_nodes(s);
	s->dst_name = 'b';
	while (s->b_len != (s->t_len))
	{
		calculate_all_costs(s);
	//	ft_play_print_values(&(s->a), &(s->b));
		move(s);
		update_sorted_status(s);
	}
//	ft_play_print_values(&(s->a), &(s->b));
	find_hi_lo_nodes(s);
	move_node_to_top(s, &(s->b), s->hi_b);
//	ft_play_print_values(&(s->a), &(s->b));
	move_node_to_top(s, &(s->a), s->lo_a);
//	ft_play_print_values(&(s->a), &(s->b));
	while (s->b_len)
	{	pa(s, 1); 	
//	ft_play_print_values(&(s->a), &(s->b));
	}
}
