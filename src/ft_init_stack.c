/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/26 17:15:25 by eduribei         ###   ########.fr       */
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
	ft_dprintf(1, "Labels:\n");
	ft_debug_print_dclist(tail, "int", offsetof(t_node, label), 1);
	ft_dprintf(1, "Index values:\n");
	ft_debug_print_dclist(tail, "int", offsetof(t_node, val), 1);
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

	//DEBUG
	t_dlist *lowest = ft_dclst_find_lowest_int(tail, offsetof(t_node, val));

	ft_dprintf(1, "lowest value is %i", ((t_node *)(lowest->content))->val);
	ft_dprintf(1, "lowest label is %i", ((t_node *)(lowest->content))->label);


}


