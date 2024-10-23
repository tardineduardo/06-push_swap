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

static bool	swap(t_dlist **tail)
{
	t_dlist	*temp; 
	int		sizea;

	sizea = ft_dclstsize(tail);
	if (sizea == 0 || sizea == 1)
		return (false);
	temp = (*tail)->next;
	(*tail)->next = (*tail)->next->next;
	(*tail)->next->prev = (*tail);
	temp->next = temp->next->next;
	temp->prev = (*tail)->next;
	temp->prev->next = temp;
	temp->next->prev = temp;
	return (true);
}

void sa(t_dlist **tail)
{
	int size;
	
	size = ft_dclstsize(tail);
	if (size == 0 || size == 1)
		return ;
	if (swap(tail));
		ft_printf("sa\n");
}

void sb(t_dlist **tail)
{
	int size;
	
	size = ft_dclstsize(tail);
	if (size == 0 || size == 1)
		return ;
	if (swap(tail));
		ft_printf("sb\n");
}

void ss(t_dlist **taila, t_dlist **tailb)
{
	bool	sa;
	bool	sb;
	int		sizea;
	int		sizeb;

	sa = false;
	sb = false;
	if (swap(taila))
		sa = true;
	if (swap(tailb))
		sb = true;
	if (sa && sb)
		ft_printf("ss\n");
	else if (sa && !sb)
		ft_printf("sa\n");
	else if (!sa && sb)
		ft_printf("sb\n");
}
