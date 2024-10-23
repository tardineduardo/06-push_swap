/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_pa_pb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:07:25 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/22 17:13:40 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push(t_dlist **src, t_dlist **dest, char *move)
{
	t_dlist	*temp;
	int sizea;
	int sizeb;
	
	sizea = ft_dclstsize(src);
	sizeb = ft_dclstsize(dest);

	if (sizea == 0)
		return;
	if (sizea == 1 && sizeb == 0)
	{
		*dest = *src;
		*src = NULL;
		ft_printf("move\n");
		return;
	}
	else if (sizea > 1 && sizeb == 0)
	{
		(*dest) = (*src)->next;
		(*src)->next = *src;
		(*src)->prev = *src;
		(*dest)->next = *dest;
		(*dest)->prev = *dest;
		ft_printf("pushed to dest\n");
		return;
	}
	else if (sizea == 1 && sizeb >= 1)
	{
		(*src)->next = (*dest)->next;
		(*src)->prev = (*dest);
		(*dest)->next = *src;
		(*dest)->next->next->prev = (*dest)->next;
		*src = NULL;
		ft_printf("pushed to dest\n");
		return;
	}

	temp = (*src)->next;
	(*src)->next->next->prev = (*src);
	(*src)->next = (*src)->next->next;
	temp->next = (*dest)->next;
	temp->prev = (*dest);
	(*dest)->next = temp;
	temp->next->prev = temp;
	ft_printf("pushed to dest\n");
}

// void pb(t_dlist **tailb, t_dlist **taila)
// {
// 	t_dlist	*temp;
// 	int sizea;
// 	int sizeb;
	
// 	sizea = ft_dclstsize(tailb);
// 	sizeb = ft_dclstsize(taila);

// 	if (sizea == 0)
// 		return;
// 	if (sizea == 1 && sizeb == 0)
// 	{
// 		*taila = *tailb;
// 		*tailb = NULL;
// 		return;
// 	}
// 	else if (sizea > 1 && sizeb == 0)
// 	{
// 		(*taila) = (*tailb)->next;
// 		(*tailb)->next = *tailb;
// 		(*tailb)->prev = *tailb;
// 		(*taila)->next = *taila;
// 		(*taila)->prev = *taila;
// 		ft_printf("pa\n");
// 		return;
// 	}
// 	else if (sizeb == 1 && sizea > 1)
// 	{
// 		(*tailb)->next = (*taila)->next;
// 		(*tailb)->prev = (*taila);
// 		(*taila)->next = *tailb;
// 		(*taila)->next->next->prev = (*taila)->next;
// 		*tailb = NULL;
// 		ft_printf("pa\n");
// 		return;
// 	}
// 	temp = (*tailb)->next;
// 	(*tailb)->next->next->prev = (*tailb);
// 	(*tailb)->next = (*tailb)->next->next;
// 	temp->next = (*taila)->next;
// 	temp->prev = (*taila);
// 	(*taila)->next = temp;
// 	temp->next->prev = temp;
// 	ft_printf("pa\n");
// }