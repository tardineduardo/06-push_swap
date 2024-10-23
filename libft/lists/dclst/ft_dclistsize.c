/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclistsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:39:36 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/22 19:41:41 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_dclstsize(t_dlist **tail)
{
	int		count_fwd;
	int		count_bck;	
	t_dlist	*trav_fwd;
	t_dlist	*trav_bck;

	if (*tail == NULL)
		return (0);
	trav_fwd = *tail;
	trav_bck = *tail;	
	count_fwd = 1;
	count_bck = 1;
	trav_fwd = trav_fwd->next;
	trav_bck = trav_bck->prev;

	while (trav_fwd != *tail)
	{
		count_fwd++;
		trav_fwd = trav_fwd->next;
		if (count_fwd > MAXLISTDEBUG)
		{
			ft_dprintf(STDERR_FILENO, "\n! Possible error in doubly circular linked list:\ncircular list doesn't return to *tail after %i steps forward.\n", MAXLISTDEBUG);
			return (-1);
		}
	}
	while (trav_bck != *tail)
	{
		count_bck++;
		trav_bck = trav_bck->prev;
		if (count_bck > MAXLISTDEBUG)
		{
			ft_dprintf(STDERR_FILENO, "\n! Possible error in doubly circular linked list:\ncircular list doesn't return to *tail after %i steps back.\n", MAXLISTDEBUG);
			return (-1);
		}
	}
	if (count_fwd == count_bck)
		return (count_fwd);
	else
	{
			ft_dprintf(STDERR_FILENO, "\n! Possible error in doubly circular linked list:\ncircular list doesn't return to *tail.\n");
		return (-1);
	}
}
