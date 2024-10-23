/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_sa_sb_ss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:23:04 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/22 21:56:42 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sa(t_dlist **taila)
{
	t_dlist	*temp; 
	int		sizea;

	temp = (*taila)->next;
	sizea = ft_dclstsize(taila);
	if (sizea == 0 || sizea == 1)
		return ;
	(*taila)->next = (*taila)->next->next;
	(*taila)->next->prev = (*taila);
	temp->next = temp->next->next;
	temp->prev = (*taila)->next;
	temp->prev->next = temp;
	temp->next->prev = temp;
	ft_printf("sa\n");
}

void sb(t_dlist **tailb)
{
	t_dlist	*temp; 
	int		sizea;

	temp = (*tailb)->next;
	sizea = ft_dclstsize(tailb);
	if (sizea == 0 || sizea == 1)
		return ;
	(*tailb)->next = (*tailb)->next->next;
	(*tailb)->next->prev = (*tailb);
	temp->next = temp->next->next;
	temp->prev = (*tailb)->next;
	temp->prev->next = temp;
	temp->next->prev = temp;
	ft_printf("sa\n");
}


void ss(t_dlist **taila, t_dlist **tailb)
{
	int		size;
	t_dlist *temp;
	bool	sa;
	bool	sb;

	size = ft_dclstsize(taila);
	if (size == 0 || size == 1)
		sa = false;
	else
	{
		(*taila)->next = (*taila)->next->next;
		(*taila)->next->prev = (*taila);
		temp->next = temp->next->next;
		temp->prev = (*taila)->next;
		temp->prev->next = temp;
		temp->next->prev = temp;
		ft_printf("sa\n");
		sa = true;
	}
	
	size = ft_dclstsize(tailb);
	if (size == 0 || size == 1)
		sb = false;
	else
	{
		(*tailb)->next = (*tailb)->next->next;
		(*tailb)->next->prev = (*tailb);
		temp->next = temp->next->next;
		temp->prev = (*tailb)->next;
		temp->prev->next = temp;
		temp->next->prev = temp;
		sb = true;
	}
	if (sa && sb)
		ft_printf("ss\n");
	else if (sa && !sb)
		ft_printf("sa\n");
	else if (!sa && sb)
		ft_printf("sb\n");
}
