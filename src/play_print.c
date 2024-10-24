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

void	put_a(t_dlist **a, int fd)
{
	t_node *edu;
	int i;
	    
	edu = (t_node *)((*a)->content);
	i = edu->value;
	ft_dprintf(fd, "\t\t\t\t+-------+\n");
	ft_dprintf(fd, "\t\t\t\t|\t%i\t|\n", i);
	ft_dprintf(fd, "\t\t\t\t+-------+\n");
}

void	put_b(t_dlist **b, int fd)
{
	t_node *edu;
	int i;
	    
	edu = (t_node *)((*b)->content);
	i = edu->value;
	ft_dprintf(fd, "\t\t\t\t\t\t\t+-------+\n");
	ft_dprintf(fd, "\t\t\t\t\t\t\t|\t%i\t|\n", i);
	ft_dprintf(fd, "\t\t\t\t\t\t\t+-------+\n");
}


void	put_ab(t_dlist **a, t_dlist **b, int fd)
{
	t_node *edu;
	t_node *maria;
	int i;
	int j;	    
	edu = (t_node *)((*a)->content);
	i = edu->value;
	maria = (t_node *)((*b)->content);
	j = maria->value;
	ft_dprintf(fd, "\t\t\t\t+-------+\t+-------+\n");
	ft_dprintf(fd, "\t\t\t\t|\t%i\t|\t|\t%i\t|\n", i, j);
	ft_dprintf(fd, "\t\t\t\t+-------+\t+-------+\n");
}

void	ft_play_print(t_dlist **a, t_dlist **b, int fd)
{
	int height;
	t_dlist *trav_a;
	t_dlist *trav_b;
	t_dlist *space_a;
	t_dlist *space_b;

	int	index_a;
	int	index_b;

	index_a = 0;
	index_b = 0;

	height = ft_dclstsize(a) + ft_dclstsize(b); 
	while (height > 0)
	{
		space_a = ft_dclsttrav_to_next(a, height - 1);
		space_b = ft_dclsttrav_to_next(b, height - 1);

		if (space_a)
		{
			trav_a = ft_dclsttrav_to_next(a, index_a);
			index_a++;
		}
		if (space_b)
		{
			trav_b = ft_dclsttrav_to_next(b, index_b);
			index_b++;
		}
		if (!space_a && !space_b)
			ft_dprintf(fd, "\n\n\n");
		else if (space_a && space_b)
			put_ab(&trav_a, &trav_b, fd);			
		else if (space_a && !space_b)
			put_a(&trav_a, fd);
		else if (!space_a && space_b)
			put_b(&trav_b, fd);
	height--;
	}
	ft_dprintf(fd, "____________________________________________________\n");
	ft_dprintf(fd, "\t\t\t\t stack a\t stack b\n");


	ft_dprintf(fd, "\n");
	ft_dprintf(fd, "\n");
	ft_dprintf(fd, "\n");
	ft_dprintf(fd, "stack a\n");
	ft_print_dclist(a, "int", offsetof(t_node, value), fd);
	ft_dprintf(fd, "stack b\n");
	ft_print_dclist(b, "int", offsetof(t_node, value), fd);

}


