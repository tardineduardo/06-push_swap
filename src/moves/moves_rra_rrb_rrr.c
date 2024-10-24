/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rra_rrb_rrr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:23:18 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 17:06:51 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_dlist **taila, int fd)
{
	int	size;

	size = ft_dclstsize(taila);
	if (size == 0 || size == 1)
		return ;
	*taila = (*taila)->next;
	ft_dprintf(fd, "rra\n");
}

void	rrb(t_dlist **tailb, int fd)
{
	int	size;

	size = ft_dclstsize(tailb);
	if (size == 0 || size == 1)
		return ;
	*tailb = (*tailb)->next;
	ft_dprintf(fd, "rrb\n");
}

void	rrr(t_dlist **taila, t_dlist **tailb, int fd)
{
	int		size;
	bool	a;
	bool	b;

	a = false;
	b = false;
	size = ft_dclstsize(taila);
	if (size > 1)
	{
		*taila = (*taila)->next;
		a = true;
	}
	size = ft_dclstsize(tailb);
	if (size > 1)
	{
		*tailb = (*tailb)->next;
		b = true;
	}
	if (a && b)
		ft_dprintf(fd, "rrr\n");
	else if (a && !b)
		ft_dprintf(fd, "rra\n");
	else if (!a && b)
		ft_dprintf(fd, "rrb\n");
}
