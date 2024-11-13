/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_list_sorted.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:55:08 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

bool ft_dclst_list_sortd(t_dll **tail, int offset)
{
	int 	curr;
	int		next;
	t_dll *trav;
	int		len;
	
	len = ft_dclstsize(tail);
	trav = (*tail)->next;

	if (len < 0)
        ft_perror_exit("ft_dclstsize error", EINVAL);
	if (len == 1 || len == 0)
        return (true);
	while(len > 1)
	{
		curr = *(int *)((char *)trav + offset);
		next = *(int *)((char *)trav->next + offset);
		if (curr > next)
			return (false);
		trav = trav->next;
		len--;
	}
	return (true);
}
