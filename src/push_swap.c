/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/21 21:12:26 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_dlist *stack_a;
	t_dlist *stack_b;

	//ft_validate_args(argc, argv);	
	stack_a = NULL;
	stack_b = NULL;	
	ft_init_stack(&stack_a, argc, argv);
	int debug = open("watch.txt", O_WRONLY | O_TRUNC | O_CREAT, 0664);

	ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));

	ft_print_dclist(&stack_a, "int", offsetof(t_node, value), 1);
	ft_printf("\n");
	//ra(&stack_a);
	ra(&stack_a);
	ft_print_dclist(&stack_a, "int", offsetof(t_node, value), 1);
	ft_printf("\n");
	rra(&stack_a);
	ft_print_dclist(&stack_a, "int", offsetof(t_node, value), 1);
	rb(&stack_b);
	rrr(&stack_a, &stack_b);
	ft_print_dclist(&stack_a, "int", offsetof(t_node, value), 1);

	close(debug);
	return (0);
}
