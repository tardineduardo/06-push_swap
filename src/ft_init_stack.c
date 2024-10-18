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


void ft_init_node(t_node *node)
{
	node->is_start = false;
	node->is_end = false;
	node->next = NULL;
	node->prev = NULL;
}


void ft_init_stack(t_list **stack, int argc, char *argv[])
{
	int		a;
	t_node	*node;

	a = 1;
	 
	while(a < argc)
	{
		node = malloc(sizeof(t_node));
			// protect
		ft_init_node(node);
		node->value = ft_atoi(argv[a]);
		if (a == 1)
			node->is_start = true;
		if (a == argc - 1)
			node->is_end = true;
		
		ft_lstadd_back(stack, ft_lstnew((void *)node));	
		a++;
	}
}