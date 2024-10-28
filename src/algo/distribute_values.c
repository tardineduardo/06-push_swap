/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:44:52 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 21:13:27 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



void	calculate_cost(t_dll **stack_a, t_dll **stack_b)
{
	



	//if TRAV < a && TRAV->PREV > a
	// custo 1 = distancia de trav pra head
	// custo 2 = distancia de a para head

}







void	distribute_values(t_dll **stack_a, t_dll **stack_b)
{
	t_dll	*best_opt;
	int		sa_len;
	int		half;

	ft_printf("INICIO\n");
	ft_play_print(stack_a, stack_b);


	// ft_debug_print_dclist(stack_a, "int", offsetof(t_nd, val), 1);
	// ft_debug_print_dclist(stack_b, "int", offsetof(t_nd, val), 1);

	sa_len = ft_dclstsize(stack_a);
	half = sa_len / 2; 
	while (sa_len > half)
	{
		calculate_cost(t_dll **stack_a, t_dll **stack_b);
		best_opt = best_push_op(stack_a, stack_b);
		ft_printf("best value to push is >>>> %i\n\n", ((t_nd *)((best_opt)->content))->val);
		move_node_to_top(stack_a, best_opt);
		pb(stack_a, stack_b, 1);
		ft_play_print(stack_a, stack_b);

		// ft_debug_print_dclist(stack_a, "int", offsetof(t_nd, label), 1);
		// ft_debug_print_dclist(stack_b, "int", offsetof(t_nd, label), 1);
		sa_len--;
	}
}
