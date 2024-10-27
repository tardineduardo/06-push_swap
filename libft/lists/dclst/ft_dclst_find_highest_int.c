/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_find_highest_int.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:17:44 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/26 19:52:24 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_dlist *ft_dclst_find_highest_int(t_dlist **tail, int offset)
{
	t_dlist	*trav;
	t_dlist	*highest_node;
	int		value;
	int		highest_val;
	
	trav = *tail;
	highest_node = *tail;

	while(trav->next->next != *tail)
	{	
		value = *(int *)((char *)trav->content + offset);
		highest_val = *(int *)((char *)highest_node->content + offset);
		if (value > highest_val)
			highest_node = trav;
		trav = trav->next;
	}
	return (highest_node);
}
