/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_find_highest_int.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:17:44 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:44:25 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_dll *ft_dclst_find_highest_int(t_dll **tail, int offset)
{
	t_dll	*trav;
	t_dll	*highest_nd;
	int		value;
	int		highest_val;
	int		len;

	len = ft_dclstsize(tail);
	trav = *tail;
	highest_nd = trav;
	while(len > 0)
	{	
		value = *(int *)((char *)trav + offset);
		highest_val = *(int *)((char *)highest_nd + offset);
		if (value > highest_val)
			highest_nd = trav;
		trav = trav->next;
		len--;
	}
	return (highest_nd);
}
