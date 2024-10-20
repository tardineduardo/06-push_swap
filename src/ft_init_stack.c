/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/17 20:59:30 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_init_stack(t_list **stack, int argc, char *argv[])
{
	int		a;
	t_node	*node;

	a = 1;
	 
	while(a < argc)
	{
		node = malloc(sizeof(t_node));
			// protect
		node->value = ft_atoi(argv[a]);
		
		ft_lstadd_back(stack, ft_lstnew((void *)node));	
		a++;
	}
}