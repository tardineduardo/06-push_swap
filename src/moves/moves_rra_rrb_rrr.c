/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rra_rrb_rrr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:23:18 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_dll **tail_a, int fd)
{
	int	size;

	size = ft_dclstsize(tail_a);
	if (size == 0 || size == 1)
		return ;
	*tail_a = (*tail_a)->next;
	ft_dprintf(fd, "rra\n");
}

void	rrb(t_dll **tail_b, int fd)
{
	int	size;

	size = ft_dclstsize(tail_b);
	if (size == 0 || size == 1)
		return ;
	*tail_b = (*tail_b)->next;
	ft_dprintf(fd, "rrb\n");
}

void	rrr(t_dll **tail_a, t_dll **tail_b, int fd)
{
	int		size;
	bool	a;
	bool	b;

	a = false;
	b = false;
	size = ft_dclstsize(tail_a);
	if (size > 1)
	{
		*tail_a = (*tail_a)->next;
		a = true;
	}
	size = ft_dclstsize(tail_b);
	if (size > 1)
	{
		*tail_b = (*tail_b)->next;
		b = true;
	}
	if (a && b)
		ft_dprintf(fd, "rrr\n");
	else if (a && !b)
		ft_dprintf(fd, "rra\n");
	else if (!a && b)
		ft_dprintf(fd, "rrb\n");
}
