/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/17 20:53:47 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_dlist *stack_a;
	t_dlist *stack_b;

	ft_validate_args(argc, argv);	
	stack_a = NULL;
	stack_b = NULL;	
	ft_init_stack(&stack_a, argc, argv);

// PAREI AQUI!!!!!!!!! TEM QUE CONFIGURAR PRA IMPRIMIR CLIST
// PAREI AQUI!!!!!!!!! TEM QUE CONFIGURAR PRA IMPRIMIR CLIST
// PAREI AQUI!!!!!!!!! TEM QUE CONFIGURAR PRA IMPRIMIR CLIST
// PAREI AQUI!!!!!!!!! TEM QUE CONFIGURAR PRA IMPRIMIR CLIST
// PAREI AQUI!!!!!!!!! TEM QUE CONFIGURAR PRA IMPRIMIR CLIST
// PAREI AQUI!!!!!!!!! TEM QUE CONFIGURAR PRA IMPRIMIR CLIST
// PAREI AQUI!!!!!!!!! TEM QUE CONFIGURAR PRA IMPRIMIR CLIST

	ft_print_list(&stack_a, "int", offsetof(t_node, value));


	
	return (0);
}
