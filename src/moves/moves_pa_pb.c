/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_pa_pb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:07:25 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 19:15:57 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void ft_push_multi_to_empty(t_dlist **src, t_dlist **dest)
{
	(*dest) = (*src)->next;
	(*src)->next = (*src)->next->next;
	(*src)->next->prev = *src;
	(*dest)->next = *dest;
	(*dest)->prev = *dest;
}

static void ft_push_single_to_multi(t_dlist **src, t_dlist **dest)
{
	(*src)->next = (*dest)->next;
	(*src)->prev = (*dest);
	(*dest)->next = *src;
	(*dest)->next->next->prev = (*dest)->next;
	*src = NULL;
}

static void ft_push_multi_to_multi(t_dlist **src, t_dlist **dest)
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

void pa(t_dlist **src, t_dlist **dest, int fd)
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
		ft_dprintf(fd, "pa\n");
		return;
	}
	else if (size_src > 1 && size_dest == 0)
		ft_push_multi_to_empty(src, dest);
	else if (size_src == 1 && size_dest >= 1)
		ft_push_single_to_multi(src, dest);
	else if (size_src >= 1 && size_dest >= 1)
		ft_push_multi_to_multi(src, dest);
	ft_dprintf(fd, "pa\n");
}

void pb(t_dlist **src, t_dlist **dest, int fd)
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
		ft_dprintf(fd, "pb\n");
		return;
	}
	else if (size_src > 1 && size_dest == 0)
		ft_push_multi_to_empty(src, dest);
	else if (size_src == 1 && size_dest >= 1)
		ft_push_single_to_multi(src, dest);
	else if (size_src >= 1 && size_dest >= 1)
		ft_push_multi_to_multi(src, dest);
	ft_dprintf(fd, "pb\n");
}
