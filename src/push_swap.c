/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 19:36:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_table	*s;

	s = malloc(sizeof(t_table));
	ft_validate_args(argc, argv);
	ft_init_stacks_and_table(s, argc, argv);
	ft_set_up_stack(s);
	s->dst_name = 'b';
	while (s->b_len == (s->t_len))
	{
		calculate_all_costs(s);
		choose_and_move_node(s);
		update_sorted_status(s);
	}
	move_node_to_top(s, &(s->b), s->hi_b);
	while (s->b_len)
		pa(s, 1);
	ft_dclstclear_simple(&(s->a));
	free(s);
}
