/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_dist_from_head.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:21:30 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_dclst_dist_from_head(t_dll **tail, t_dll *node)
{
	int		i;
	int		list_len;
	t_dll	*trav_fwd;
	t_dll	*trav_bck;

	i = 0;
	list_len = ft_dclstsize(tail);
	if (list_len == -1)
		ft_error_exit("List size error.", 1);
	trav_fwd = node;
	trav_bck = node;
	while (i < list_len)
	{
		if (trav_fwd == (*tail)->next)
			return (i);
		if (trav_bck == (*tail)->next)
			return (-i);
		i++;
		trav_fwd = trav_fwd->next;
		trav_bck = trav_bck->prev;	
	}
	ft_error_exit("Invalid parameters: can't find head of the list.", 1);
}