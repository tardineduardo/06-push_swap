/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/18 17:51:56 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_match_index(t_table *s, int *sorted_labels)
{
	t_dll	*trav;
	int		i;
	int		j;

	i = 0;
	trav = s->a;
	while (i < s->t_len)
	{
		j = 0;
		trav = trav->next;
		while (j < s->t_len)
		{
			if (trav->label == sorted_labels[j])
			{
				trav->value = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return ;
}

static void	ft_assign_indexes_to_labels(t_table *s)
{
	int		i;
	int		*sorted_labels;
	t_dll	*trav;

	sorted_labels = malloc(s->t_len * sizeof(int));
	if (!sorted_labels)
		ft_perror_exit("malloc (indexes)", errno);
	trav = s->a;
	i = 0;
	while (i < s->t_len)
	{
		trav = trav->next;
		sorted_labels[i] = trav->label;
		i++;
	}
	ft_sort_int_array_bubble(sorted_labels, s->t_len);
	ft_match_index(s, sorted_labels);
	free(sorted_labels);
	return ;
}

static void	ft_init_node_values(t_dll *new)
{
	new->next = new;
	new->prev = new;
	new->procedent = NULL;
	new->cost = -1;
	new->cost_rev = -1;
	new->cost_rot = -1;
	new->cost_opo_srot_drev = -1;
	new->cost_opo_srev_drot = -1;
	new->move_rev = false;
	new->move_rot = false;
	new->move_opo_srot_drev = false;
	new->move_opo_srev_drot = false;
	return ;
}

void	ft_malloc_and_init_nodes(t_table *s, int argc, char *argv[])
{
	int		a;
	t_dll	*new;

	s->a = NULL;
	s->b = NULL;
	a = 1;
	while (a < argc)
	{
		new = malloc(sizeof(t_dll));
		if (!new)
		{
			ft_dclstclear_simple(&(s->a));
			ft_perror_exit("malloc (stack init)", errno);
		}
		new->label = ft_atoi(argv[a]);
		ft_init_node_values(new);
		ft_dclstadd_back(&(s->a), new);
		a++;
	}
}

void	ft_init_stacks_and_table(t_table *s, int argc, char *argv[])
{
	ft_malloc_and_init_nodes(s, argc, argv);
	s->a_len = ft_dclstsize(&(s->a));
	s->b_len = 0;
	s->t_len = s->a_len + s->b_len;
	s->limit_low = s->t_len / 3;
	s->limit_high = (s->t_len * 2) / 3;
	s->a_partially_sorted = false;
	s->dst_name = 0;
	ft_assign_indexes_to_labels(s);
	if (s->a_len <= 5)
		s->mode = 's';
	else if (s->a_len > 5 && s->a_len <= 500)
		s->mode = 'm';
	else if (s->a_len > 5)
		s->mode = 'l';
	ft_find_hi_lo_nodes(s);
	ft_update_partially_sorted_status(s);
	return ;
}
