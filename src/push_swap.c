/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:04 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_table	*s;

	s = malloc(sizeof(t_table));
	ft_validate_args(argc, argv);
	ft_init_stacks_and_table(s, argc, argv);
	ft_play_print_values(&(s->a), &(s->b));
	ft_init_stack_b(s);
	if (s->already_sorted)
	{
		move_node_to_top(s, &(s->a), s->lo_a);
		return (0);
	}
	else if (s->a_partially_sorted)
	{
		s->dst_name = 'a';
		// move elements back from b to a.
		return(0);
	}
	else
	{
		



	}	
	
	find_hi_lo_nodes(s);
	s->dst_name = 'b';
	while (s->b_len != (s->t_len))
	{
		calculate_all_costs(s);
		move(s);
	}
	find_hi_lo_nodes(s);
	move_node_to_top(s, &(s->b), s->hi_b);
	move_node_to_top(s, &(s->a), s->lo_a);
	while (s->b_len)
		pa(s, 1); 	
}
