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


static void ft_run_algo_already_sorted(t_table *s)
{
	s->dst_name = 'a';
	find_hi_lo_nodes(s);
	ft_move_node_to_top(s, &(s->a), s->lo_a);
	return ;
}

static void ft_run_algo_low(t_table *s)
{
	low_ft_init_stack_b(s);
	find_hi_lo_nodes(s);
	while (s->b_len != 0)
	{
		s->dst_name = 'b';
		ft_move_node_to_top(s, &(s->b), s->hi_b);
		s->dst_name = 'a';
		//ft_move_node_to_top(s, &(s->a), s->lo_a);
		ft_move_node_to_top(s, &(s->a), s->b->next->procedent);
		ft_pa(s, 1);
		find_hi_lo_nodes(s);
	}
	s->dst_name = 'a';
	ft_move_node_to_top(s, &(s->a), s->lo_a);
	return ;
}

static void run_algo_high(t_table *s)
{
	ft_init_stack_b(s);
	s->dst_name = 'b';
	while (s->b_len != (s->t_len))
	{
		calculate_all_costs(s);
		ft_move(s);
	}
	find_hi_lo_nodes(s);
	ft_move_node_to_top(s, &(s->b), s->hi_b);
	ft_move_node_to_top(s, &(s->a), s->lo_a);
	while (s->b_len)
		ft_pa(s, 1);
	return ;
}

int	main(int argc, char *argv[])
{
	t_table	*s;

	s = malloc(sizeof(t_table));
	ft_validate_args(argc, argv);
	ft_init_stacks_and_table(s, argc, argv);

	if (s->a_partially_sorted)
		ft_run_algo_already_sorted(s);
	if (s->mode == 's')
		ft_run_algo_low(s);
	else if (s->mode == 'm' || s->mode == 'l')
		run_algo_high(s);	
	ft_dclstclear_simple(&(s->a));
	free(s);
}
