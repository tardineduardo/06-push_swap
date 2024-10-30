/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/30 17:25:22 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack_debug(t_info *s)
{
	ft_dprintf(1, "Labels:\n");
	ft_debug_print_dclist(&(s->a), "int", offsetof(t_dll, label), 1);
	ft_dprintf(1, "Index values:\n");
	ft_debug_print_dclist(&(s->a), "int", offsetof(t_dll, value), 1);

	ft_dprintf(1, "Labels:\n");
	ft_debug_print_dclist(&(s->b), "int", offsetof(t_dll, label), 1);
	ft_dprintf(1, "Index values:\n");
	ft_debug_print_dclist(&(s->b), "int", offsetof(t_dll, value), 1);


	t_dll *lowest = ft_dclst_find_lowest_int(&(s->a), offsetof(t_dll, value));
	ft_dprintf(1, "lowest label is %i\n", lowest->label);
	ft_dprintf(1, "lowest value is %i\n\n", lowest->value);

	t_dll *highest = ft_dclst_find_highest_int(&(s->a), offsetof(t_dll, value));
	ft_dprintf(1, "highest label is %i\n", highest->label);
	ft_dprintf(1, "highest value is %i\n\n", highest->value);


	if (ft_dclst_circ_sortd(&(s->a), 'i', 'n', offsetof(t_dll, value)))
		ft_printf("list is circle-sorted\n");
	else
		ft_printf("list is NOT circle-sorted\n");
	
	if (ft_dclst_circ_sortd(&(s->a), 'i', 'r', offsetof(t_dll, value)))
		ft_printf("list is circle-sorted in reverse\n");
	else
		ft_printf("list is NOT circle-sorted in reverse\n");
	
	if (ft_dclst_list_sortd(&(s->a), "int", 'n', offsetof(t_dll, value)))
		ft_printf("list is list-sorted\n");
	else
		ft_printf("list is NOT list-sorted\n");	
	
	if (ft_dclst_list_sortd(&(s->a), "int", 'r', offsetof(t_dll, value)))
		ft_printf("list is list-sorted in reverse\n");
	else
		ft_printf("list is NOT list-sorted in reverse\n");

	int distancelowest = ft_dclst_dist_head_bidi(&(s->a), lowest);
	int distancehighest = ft_dclst_dist_head_bidi(&(s->a), highest);

	ft_printf("\nthe distance from the lowest value to the head is: %i\n", distancelowest);
	ft_printf("the distance from the highest value to the head is: %i\n", distancehighest);

	

}
