/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/11 22:19:22 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void run_algo_low(t_table *s)
{
	PRINT;
	low_ft_init_stack_b(s); PRINT;
	find_hi_lo_nodes(s);
	
	s->dst_name = 'a';
	while (s->b_len != 0)
	{
		move_node_to_top(s, &(s->a), s->b->next->procedent); PRINT;
		pa(s, 1);
		find_hi_lo_nodes(s);
	}
	move_node_to_top(s, &(s->a), s->lo_a); PRINT;
	PRINT;
	return ;

}

static void run_algo_high(t_table *s)
{
	ft_init_stack_b(s);
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


int	main(int argc, char *argv[])
{
	t_table	*s;

	s = malloc(sizeof(t_table));
	ft_validate_args(argc, argv);
	ft_init_stacks_and_table(s, argc, argv);
	find_hi_lo_nodes(s);
	update_partially_sorted_status(s);
	if (s->a_partially_sorted)
	{
		s->dst_name = 'a';
		find_hi_lo_nodes(s);
		move_node_to_top(s, &(s->a), s->lo_a);
		return (0);
	}
	if (s->t_len <= 5)
		run_algo_low(s);
	else if (s->t_len > 5)
		run_algo_high(s);	
}
