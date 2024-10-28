/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 21:18:41 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_dll *stack_a;
	t_dll *stack_b;

	//ft_validate_args(argc, argv);	
	stack_a = NULL;
	stack_b = NULL;

	ft_init_stack(&stack_a, argc, argv);

	init_stack_debug(&stack_a);

	distribute_values(&stack_a, &stack_b);


}
