/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_find_lowest_int.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:17:44 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/26 17:15:56 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_dlist *ft_dclst_find_lowest_int(t_dlist **tail, int offset)
{
	t_dlist	*trav;
	t_dlist	*lowest_node;
	int		value;
	int		lowest_val;
	int		len;

	len = ft_dclstsize(tail);
	trav = *tail;
	lowest_node = trav;
	while(len > 0)
	{	
		value = *(int *)((char *)trav->content + offset);
		lowest_val = *(int *)((char *)lowest_node->content + offset);
		if (value < lowest_val)
			lowest_node = trav;
		trav = trav->next;
		len--;
	}
	return (lowest_node);
}


