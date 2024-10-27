/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_sa_sb_ss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:23:04 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 15:58:19 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	swap(t_dlist **tail)
{
	t_dlist	*temp;
	int		size;

	size = ft_dclstsize(tail);
	if (size == 0 || size == 1)
		return (false);
	else if (size == 2)
	{
		(*tail) = (*tail)->next;
	}
	else
	{
		temp = (*tail)->next;
		(*tail)->next = (*tail)->next->next;
		(*tail)->next->prev = (*tail);
		temp->next = temp->next->next;
		temp->prev = (*tail)->next;
		temp->prev->next = temp;
		temp->next->prev = temp;
	}
	return (true);
}

void	sa(t_dlist **tail, int fd)
{
	if (swap(tail))
		ft_dprintf(fd, "sa\n");
}

void	sb(t_dlist **tail, int fd)
{
	if (swap(tail))
		ft_dprintf(fd, "sb\n");
}

void	ss(t_dlist **tail_a, t_dlist **tail_b, int fd)
{
	bool	sa;
	bool	sb;

	sa = false;
	sb = false;
	if (swap(tail_a))
		sa = true;
	if (swap(tail_b))
		sb = true;
	if (sa && sb)
		ft_dprintf(fd, "ss\n");
	else if (sa && !sb)
		ft_dprintf(fd, "sa\n");
	else if (!sa && sb)
		ft_dprintf(fd, "sb\n");
}
