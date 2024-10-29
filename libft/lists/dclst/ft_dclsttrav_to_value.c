/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclsttrav_to_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:42:18 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/28 20:30:29 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static t_dll	*ft_search_reverse(t_dll **tail, int value, int offset)
{
	t_dll		*trav;

	trav = (*tail);
	if (*(int *)((char *)(trav + offset)) == value)
		return (trav);
	trav = trav->prev;
	while (trav != (*tail))
	{
		if (*(int *)((char *)(trav + offset)) == value)
			return (trav);
		trav = trav->prev;
	}
	return (NULL);
}

static t_dll	*ft_search_normal(t_dll **tail, int value, int offset)
{
	t_dll		*trav;

	trav = (*tail)->next;
	while (trav != (*tail))
	{
		if (*(int *)((char *)(trav + offset)) == value)
			return (trav);
		trav = trav->next;
	}
	return (NULL);
}

//teste
t_dll	*ft_dclsttrav_to_value(t_dll **tail, int value, char mode, int offset)
{
	if (mode == 'n')
		return(ft_search_normal(tail, value, offset));
	else if (mode == 'r')
		return(ft_search_reverse(tail, value, offset));
	else
		ft_error_exit("Invalid mode. Use 'n' for normal, 'r' for reverse.\n", 1);
	return (NULL);
}
