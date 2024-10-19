/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_mid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:49:50 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/18 22:11:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/* This function inserts a node in the middle of a circular linked list.
It takes as a parameter the position where the node should be inserted.
Positions are indexed from zero, and valid positions range from 0 to size + 1.
If position is zero, ft_clistadd_front is called.
If position is list_size + 1, ft_clistadd_back is called.*/

static int	ft_wrap_position(t_list **tail, int pos)
{
	int list_size;
	
	list_size = ft_clstsize(tail);
	if (list_size == 0)
		return (0);
	if (list_size == 1 && (pos == 0 || pos == 1))
		return (pos);
	if (list_size == 1 && (pos != 0 && pos != 1))
	{
		ft_putstr_fd("Warning: position > list_size. Wrapping around!\n", STDERR_FILENO);
		return (pos % 2);
	}
	if (pos > list_size + 1)
	{
		ft_putstr_fd("Warning: position > list_size. Wrapping around!\n", STDERR_FILENO);
		return (pos % list_size);
	}
	return (pos);
}

void	ft_clstadd_mid_wrap(t_list **tail, t_list *new, size_t pos)
{
	t_list	*trav;
	size_t	clistsize;

	clistsize = ft_clistsize(tail);
	pos = ft_wrap_position(tail, pos);
	if (clistsize == 0)
	{
		*tail = new;
		new->next = new;
	}
	else if (pos == 0)
		ft_clstadd_front(tail, new);
	else if (pos == clistsize)
		ft_clstadd_back(tail, new);
	else
	{
		trav = (*tail)->next;
		while ((pos--) > 0)
			trav = trav->next;
		new->next = trav->next;
		trav->next = new;
	}
}

