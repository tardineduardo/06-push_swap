/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_find_lowest_int.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:17:44 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:44:25 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dll *find_lowest_cost(t_dll **tail)
{
	t_dll	*trav;
	t_dll	*lowest_node;

	if (!tail || !(*tail))
		return (NULL);
	trav = (*tail)->next;
	lowest_node = trav;
	while(1)
	{	
		if (trav->cost < lowest_node->cost)
			lowest_node = trav;
		trav = trav->next;
		if (trav == (*tail)->next)
			break ;
	}
	return (lowest_node);
}
