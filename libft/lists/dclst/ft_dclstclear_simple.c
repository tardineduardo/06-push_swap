/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclstclear_simple.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:54:08 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 19:19:49 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_dclstclear_simple(t_dll **lst)
{
	t_dll	*temp1;
	t_dll	*temp2;
	int		llen;
	int		i;
	
	if (lst == NULL || *lst == NULL)
		return ;
	llen = ft_dclstsize(lst);
	temp1 = *lst;
	i = 0;
	while (i < llen)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
		i++;
	}
	*lst = NULL;
}
