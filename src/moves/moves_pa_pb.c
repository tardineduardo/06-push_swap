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

static void ft_push_src_9_dest_0(t_dlist **src, t_dlist **dest)
{
	(*dest) = (*src)->next;
	(*src)->next = *src;
	(*src)->prev = *src;
	(*dest)->next = *dest;
	(*dest)->prev = *dest;
}

static void ft_push_src_1_dest_9(t_dlist **src, t_dlist **dest)
{
	(*src)->next = (*dest)->next;
	(*src)->prev = (*dest);
	(*dest)->next = *src;
	(*dest)->next->next->prev = (*dest)->next;
	*src = NULL;
}

static void ft_push_src_9_dest_9(t_dlist **src, t_dlist **dest)
{
	t_dlist	*temp;

	temp = (*src)->next;
	(*src)->next->next->prev = (*src);
	(*src)->next = (*src)->next->next;
	temp->next = (*dest)->next;
	temp->prev = (*dest);
	(*dest)->next = temp;
	temp->next->prev = temp;
}

void pa(t_dlist **src, t_dlist **dest)
{
	int		size_src;
	int		size_dest;
	
	size_src = ft_dclstsize(src);
	size_dest = ft_dclstsize(dest);
	if (size_src == 0)
		return;
	else if (size_src == 1 && size_dest == 0)
	{
		*dest = *src;
		*src = NULL;
		ft_printf("pa\n");
		return;
	}
	else if (size_src > 1 && size_dest == 0)
		ft_push_src_9_dest_0(src, dest);
	else if (size_src == 1 && size_dest >= 1)
		ft_push_src_1_dest_9(src, dest);
	else if (size_src >= 1 && size_dest >= 1)
		ft_push_src_1_dest_9(src, dest);
	ft_printf("pa\n");
}

void pb(t_dlist **src, t_dlist **dest)
{
	int		size_src;
	int		size_dest;
	
	size_src = ft_dclstsize(src);
	size_dest = ft_dclstsize(dest);
	if (size_src == 0)
		return;
	else if (size_src == 1 && size_dest == 0)
	{
		*dest = *src;
		*src = NULL;
		ft_printf("pb\n");
		return;
	}
	else if (size_src > 1 && size_dest == 0)
		ft_push_src_9_dest_0(src, dest);
	else if (size_src == 1 && size_dest >= 1)
		ft_push_src_1_dest_9(src, dest);
	else if (size_src >= 1 && size_dest >= 1)
		ft_push_src_1_dest_9(src, dest);
	ft_printf("pb\n");
}
