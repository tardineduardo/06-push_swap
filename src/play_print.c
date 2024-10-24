/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:41:34 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 21:53:28 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_space(t_dlist **a, t_dlist **b, int fd)
{
	int height;
	int sizea;
	int sizeb;
	int	space;
	int i;

	sizea = ft_dclstsize(a);
	sizeb = ft_dclstsize(b);
	height = ft_dclstsize(a) + ft_dclstsize(b);

	if (sizea > sizeb)
		space = height - sizea;

	if (sizeb > sizea)
		space = height - sizeb;

	i = 0;
	while (i < height)
		ft_dprintf(fd, "\n");
}

void	put_a(t_dlist *a, int fd)
{
	int i;

	i = ((t_node *)(a->content))->value;
	ft_dprintf(fd, "\t\t\t\t+-------+\n");
	ft_dprintf(fd, "\t\t\t\t|\t%i\t|\n", i);
	ft_dprintf(fd, "\t\t\t\t+-------+\n");
}


void	ft_play_print(t_dlist **a, t_dlist **b, int fd)
{
	int height;
	t_dlist *trav_a;
	t_dlist *trav_b;

	height = ft_dclstsize(a) + ft_dclstsize(a); 
	int i = 0;
	while (i < height)
	{
		a = ft_dclsttrav_to_next(a, i);
		b = ft_dclsttrav_to_next(b, i);

		if (!a && !b)
			put_space(a, b, fd);
		//if (a && b)
		//	put_ab(a, b, fd);			
		if (a && !b)
			put_a(a, fd);
		//if (!a && b)
		///	put_b(b, fd);
	}
}


