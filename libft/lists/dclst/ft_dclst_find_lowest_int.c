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

#include "../../libft.h"

t_dll *ft_dclst_find_lowest_int(t_dll **tail, int offset)
{
	t_dll	*trav;
	t_dll	*lowest_nd;
	int		value;
	int		lowest_val;
	int		len;

	len = ft_dclstsize(tail);
	trav = *tail;
	lowest_nd = trav;
	while(len > 0)
	{	
		value = *(int *)((char *)trav + offset);
		lowest_val = *(int *)((char *)lowest_nd + offset);
		if (value < lowest_val)
			lowest_nd = trav;
		trav = trav->next;
		len--;
	}
	return (lowest_nd);
}


