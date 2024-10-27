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

void init_stack_debug(t_dlist **stack)
{
	ft_dprintf(1, "Labels:\n");
	ft_debug_print_dclist(stack, "int", offsetof(t_node, label), 1);
	ft_dprintf(1, "Index values:\n");
	ft_debug_print_dclist(stack, "int", offsetof(t_node, val), 1);

	t_dlist *lowest = ft_dclst_find_lowest_int(stack, offsetof(t_node, val));
	ft_dprintf(1, "lowest label is %i\n", ((t_node *)(lowest->content))->label);
	ft_dprintf(1, "lowest value is %i\n\n", ((t_node *)(lowest->content))->val);

	t_dlist *highest = ft_dclst_find_highest_int(stack, offsetof(t_node, val));
	ft_dprintf(1, "highest label is %i\n", ((t_node *)(highest->content))->label);
	ft_dprintf(1, "highest value is %i\n\n", ((t_node *)(highest->content))->val);


	if (ft_dclst_circ_sortd(stack, "int", 'n', offsetof(t_node, val)))
		ft_printf("list is circle-sorted\n");
	else
		ft_printf("list is NOT circle-sorted\n");
	
	if (ft_dclst_circ_sortd(stack, "int", 'r', offsetof(t_node, val)))
		ft_printf("list is circle-sorted in reverse\n");
	else
		ft_printf("list is NOT circle-sorted in reverse\n");
	
	if (ft_dclst_list_sortd(stack, "int", 'n', offsetof(t_node, val)))
		ft_printf("list is list-sorted\n");
	else
		ft_printf("list is NOT list-sorted\n");	
	
	if (ft_dclst_list_sortd(stack, "int", 'r', offsetof(t_node, val)))
		ft_printf("list is list-sorted in reverse\n");
	else
		ft_printf("list is NOT list-sorted in reverse\n");
}	
