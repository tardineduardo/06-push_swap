/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/22 21:55:18 by eduribei         ###   ########.fr       */
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
	ft_init_stack2(&stack_a, argc, argv);
	ft_init_stack1(&stack_b, argc, argv);

	int debug = open("watch.txt", O_WRONLY | O_TRUNC | O_CREAT, 0664);

	ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	ft_printf("****************************************\n\n");


	sa(&stack_a);
	ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	ft_printf("---------------------------\n\n");

	ss(&stack_a, &stack_b);
	ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	ft_printf("---------------------------\n\n");

	// rrr(&stack_a, &stack_b);
	// ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	// ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	// ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	// ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	// ft_printf("---------------------------\n\n");


	// sa(&stack_a);
	// ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	// ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	// ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	// ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	// ft_printf("---------------------------\n\n");

	// sb(&stack_b);
	// ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	// ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	// ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	// ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	// ft_printf("---------------------------\n\n");

	// ss(&stack_a, &stack_b);
	// ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	// ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	// ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	// ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	// ft_printf("---------------------------\n\n");

	// 	ss(&stack_a, &stack_b);
	// ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	// ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	// ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	// ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	// ft_printf("---------------------------\n\n");

	// ra(&stack_a);
	// ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	// ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	// ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	// ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	// ft_printf("---------------------------\n\n");

	// ra(&stack_a);
	// ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	// ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	// ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	// ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	// ft_printf("********\n\n");

	// ft_printf("dest {pb}\n");
	// push(&stack_a, &stack_b);
	// ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	// ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	// ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	// ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	// ft_printf("****************************************\n\n");

	// ft_printf("dest {pa}\n");
	// push(&stack_b, &stack_a);
	// ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	// ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	// ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	// ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	// ft_printf("****************************************\n\n");

	// ft_printf("dest {pb}\n");
	// push(&stack_a, &stack_b);
	// ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	// ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	// ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	// ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	// ft_printf("****************************************\n\n");

	// ft_printf("dest {pb}\n");
	// push(&stack_a, &stack_b);
	// ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	// ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	// ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	// ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	// ft_printf("****************************************\n\n");

	// ft_printf("dest {pb}\n");
	// push(&stack_a, &stack_b);
	// ft_printf("stack_a size = %i\n", ft_dclstsize(&stack_a));
	// ft_print_dclist(&stack_a, "string", offsetof(t_node, stringz), 1);
	// ft_printf("stack_b size = %i\n", ft_dclstsize(&stack_b));
	// ft_print_dclist(&stack_b, "string", offsetof(t_node, stringz), 1);
	// ft_printf("****************************************\n\n");



	close(debug);
	return (0);
}
