/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_is_circle_sorted.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:57:54 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/26 20:58:45 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

bool is_circle_sorted(t_dlist **tail, char stack_a_or_b)
{
	int 	curr;
	int		next;
	
	t_dlist *trav;
	t_dlist *start;

	if (stack_a_or_b == 'a')
		trav = ft_dclst_find_lowest_int(tail, offsetof(t_node, val));
	if (stack_a_or_b == 'b')
		trav = ft_dclst_find_highest_int(tail, offsetof(t_node, val));
	start = trav;
	while(trav->next->next != start)
	{
		curr = ((t_node *)(trav->content))->val;
		next = ((t_node *)(trav->next->content))->val;
		if (s == 'a')
			if (curr > next)
				return (false);
		else if (s == 'b')
			if (curr < next)
				return (false);
	}
	return (true);
}