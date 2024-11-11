/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:33:44 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/18 15:06:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_dclstclear_simple(t_dll **lst)
{
	t_dll	*temp1;
	t_dll	*temp2;

	if (lst == NULL || *lst == NULL)
		return ;
	temp1 = *lst;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	*lst = NULL;
}
