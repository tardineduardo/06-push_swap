/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/28 21:06:43 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_assign_indexes_to_labels(t_dll **tail)
{
	int		i;
	int		j;
	int		len;
	int		*sorted_labels;
	t_dll	*trav;

	len = ft_dclstsize(tail);
	sorted_labels = malloc(len * sizeof(int));
	if (!sorted_labels)
		ft_perror_exit("assinging indexes", errno);
	trav = *tail;
	i = 0;
	while (i < len)
	{
		trav = trav->next;
		sorted_labels[i] = trav->label;
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
			if (trav->label == sorted_labels[j])
			{
				trav->val = j;
				break ;
			}
			j++;
		}
		i++;
	}



}

void	ft_init_stacks(t_info *s, int argc, char *argv[])
{
	int		a;
	t_dll	*new;

	s->a = NULL;
	s->b = NULL;
	a = 1;
	while (a < argc)
	{
		new = malloc(sizeof(t_dll));
			// protect ALL MALLOCS, INCLUDING NODES ALREADY ALLOCATED.
			// 
		new->cost = -1;
		new->label = ft_atoi(argv[a]);
		new->next = new;
		new->prev = new;
		ft_dclstadd_back(s->a, new);
		a++;
	}
	s->a_len = ft_dclstsize(s->a);
	s->b_len = 0;
	ft_assign_indexes_to_labels(s->a);
}
