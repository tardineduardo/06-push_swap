/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_sa_sb_ss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:23:04 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	swap(t_dll **tail)
{
	t_dll	*temp;
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

void	sa(t_info *s, int fd)
{
	if (swap(&(s->a)))
		ft_dprintf(fd, "sa\n");
}

void	sb(t_info *s, int fd)
{
	if (swap(&(s->b)))
		ft_dprintf(fd, "sb\n");
}

void	ss(t_info *s, int fd)
{
	bool	sa;
	bool	sb;

	sa = false;
	sb = false;
	if (swap(&(s->a)))
		sa = true;
	if (swap(&(s->b)))
		sb = true;
	if (sa && sb)
		ft_dprintf(fd, "ss\n");
	else if (sa && !sb)
		ft_dprintf(fd, "sa\n");
	else if (!sa && sb)
		ft_dprintf(fd, "sb\n");
}
