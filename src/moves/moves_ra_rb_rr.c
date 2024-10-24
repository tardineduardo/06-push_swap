/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ra_rb_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:31:26 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 17:05:44 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_dlist **tail, int fd)
{
	int	size;

	size = ft_dclstsize(tail);
	if (size == 0 || size == 1)
		return ;
	*tail = (*tail)->prev;
	ft_dprintf(fd, "ra\n");
}

void	rb(t_dlist **tail, int fd)
{
	int	size;

	size = ft_dclstsize(tail);
	if (size == 0 || size == 1)
		return ;
	*tail = (*tail)->prev;
	ft_dprintf(fd, "rb\n");
}

void	rr(t_dlist **taila, t_dlist **tailb, int fd)
{
	int		size;
	bool	a;
	bool	b;

	a = false;
	b = false;
	size = ft_dclstsize(taila);
	if (size > 1)
	{
		*taila = (*taila)->prev;
		a = true;
	}
	size = ft_dclstsize(tailb);
	if (size > 1)
	{
		*tailb = (*tailb)->prev;
		b = true;
	}
	if (a && b)
		ft_dprintf(fd, "rr\n");
	else if (a && !b)
		ft_dprintf(fd, "ra\n");
	else if (!a && b)
		ft_dprintf(fd, "rb\n");
}
