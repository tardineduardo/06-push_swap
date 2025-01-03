/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:49:50 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/12 18:40:48 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// back means the end of the list, right after the last element.
void	ft_dclstadd_back(t_dll **tail, t_dll *new)
{
	if (new == NULL)
		return ;
	if (*tail == NULL)
		*tail = new;
	else
	{
		new->next = (*tail)->next;
		new->prev = *tail;
		(*tail)->next = new;
		new->next->prev = new;
		*tail = new;
	}
}
