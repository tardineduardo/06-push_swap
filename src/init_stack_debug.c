/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/28 21:05:06 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack_debug(t_dll **stack)
{
	ft_dprintf(1, "Labels:\n");
	ft_debug_print_dclist(stack, "int", offsetof(t_dll, label), 1);
	ft_dprintf(1, "Index values:\n");
	ft_debug_print_dclist(stack, "int", offsetof(t_dll, val), 1);

	t_dll *lowest = ft_dclst_find_lowest_int(stack, offsetof(t_dll, val));
	ft_dprintf(1, "lowest label is %i\n", lowest->label);
	ft_dprintf(1, "lowest value is %i\n\n", lowest->val);

	t_dll *highest = ft_dclst_find_highest_int(stack, offsetof(t_dll, val));
	ft_dprintf(1, "highest label is %i\n", highest->label);
	ft_dprintf(1, "highest value is %i\n\n", highest->val);


	if (ft_dclst_circ_sortd(stack, "int", 'n', offsetof(t_dll, val)))
		ft_printf("list is circle-sorted\n");
	else
		ft_printf("list is NOT circle-sorted\n");
	
	if (ft_dclst_circ_sortd(stack, "int", 'r', offsetof(t_dll, val)))
		ft_printf("list is circle-sorted in reverse\n");
	else
		ft_printf("list is NOT circle-sorted in reverse\n");
	
	if (ft_dclst_list_sortd(stack, "int", 'n', offsetof(t_dll, val)))
		ft_printf("list is list-sorted\n");
	else
		ft_printf("list is NOT list-sorted\n");	
	
	if (ft_dclst_list_sortd(stack, "int", 'r', offsetof(t_dll, val)))
		ft_printf("list is list-sorted in reverse\n");
	else
		ft_printf("list is NOT list-sorted in reverse\n");

	int distancelowest = ft_dclst_dist_from_head(stack, lowest);
	int distancehighest = ft_dclst_dist_from_head(stack, highest);

	ft_printf("\nthe distance from the lowest value to the head is: %i\n", distancelowest);
	ft_printf("the distance from the highest value to the head is: %i\n", distancehighest);

}
