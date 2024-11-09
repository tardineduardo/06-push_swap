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
	ft_init_stack_b(s);
	find_hi_lo_nodes(s);
	s->dst_name = 'b';
	while (s->b_len != (s->t_len))
	{
		calculate_all_costs(s);
		move(s);
		update_sorted_status(s);
	}
	t_dll *hb = ft_dclst_find_highest_int(&(s->b), offsetof(t_dll, value));
	t_dll *la = ft_dclst_find_lowest_int(&(s->a), offsetof(t_dll, value));
	move_node_to_top(s, &(s->b), hb);
	move_node_to_top(s, &(s->a), hb);
	while (s->b_len)
		pa(s, 1);
}
