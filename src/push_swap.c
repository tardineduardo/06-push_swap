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
	ft_init_stacks_and_table(s, argc, argv);	PRINT;
	find_hi_lo_nodes(s);
	ft_init_stack_b(s);							PRINT;
	if (s->already_sorted)
	{
		s->dst_name = 'a';
		find_hi_lo_nodes(s);
		move_node_to_top(s, &(s->a), s->lo_a);	PRINT;
		return (0);
	}
	update_partially_sorted_status(s);
	if (s->a_partially_sorted)
	{
		swapping_works(s);						PRINT;
		find_hi_lo_nodes(s);
		s->dst_name = 'a';
		while (s->a_len != (s->t_len))
		{
			swapping_works(s);					PRINT;
			calculate_all_costs(s);				PRINT;
			move(s);							PRINT;
		}
		return(0);
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
