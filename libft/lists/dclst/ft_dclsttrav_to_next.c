/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclsttrav_to_next.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:52:04 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 21:46:39 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_dlist	*ft_dclsttrav_to_next(t_dlist **tail, size_t index)
{
	int		i;
	int		len;
	t_dlist *trav;

	trav = *tail;
	len = ft_dclstsize(tail);
	if (index > len - 1 || len == 0)
		return (NULL);
	if (index == 0)
		return (trav);
	i = 0;
	while (i < len)
	{
		trav = trav->next;
	}
	return (trav);
}
