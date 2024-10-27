/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/26 19:37:15 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_assign_indexes_to_labels(t_dlist **tail)
{
	int		i;
	int		j;
	int		len;
	int		*sorted_labels;
	t_dlist	*trav;

	len = ft_dclstsize(tail);
	sorted_labels = malloc(len * sizeof(int));
	if (!sorted_labels)
		ft_perror_exit("assinging indexes", errno);

	trav = *tail;
	i = 0;
	while (i < len)
	{
		trav = trav->next;
		sorted_labels[i] = ((t_node *)((trav)->content))->label;
		i++;
	}
	ft_sort_int_array_bubble(sorted_labels, len);
	i = 0;
	trav = *tail;
	while (i < len)
	{
		j = 0;
		trav = trav->next;
		while (j < len)
		{
			if (((t_node *)((trav)->content))->label == sorted_labels[j])
			{
				((t_node *)((trav)->content))->val = j;
				break ;
			}
			j++;
		}
		i++;
	}



}

void	ft_init_stack(t_dlist **tail, int argc, char *argv[])
{
	int		a;
	t_node	*node;

	a = 1;
	while (a < argc)
	{
		node = malloc(sizeof(t_node));
			// protect ALL MALLOCS, INCLUDING NODES ALREADY ALLOCATED.
		node->label = ft_atoi(argv[a]);
		ft_dclstadd_back(tail, ft_dclstnew((void *)node));
		a++;
	}
	ft_assign_indexes_to_labels(tail);




}


