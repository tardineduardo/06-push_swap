/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:49:50 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/18 17:22:28 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_clstadd_back(t_list **tail, t_list *new)
{
	if (*tail == NULL)
	{
		*tail = new;
		new->next = new;
	}
	else
	{
		new->next = (*tail)->next;
		(*tail)->next = new;
		*tail = new;
	}
}

