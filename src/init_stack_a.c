/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 15:38:57 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_pro_node(t_info *s)
{
	t_dll *trav_a;
	t_dll *trav_b;
	int	a;
	int b;
	
	a = 0;
	trav_a = s->a;
	trav_b = s->a->prev;
	while (a < s->a_len)
	{
		b = 0;
		while (b < s->a_len)
		{
			if (trav_a->value != s->a_len - 1)
			{
				if (trav_a->value == trav_b->value - 1)
					trav_a->pro = trav_b;
				b++;
				trav_b = trav_b->prev;
			}
			else
			{
				if (trav_b->value == 0)
					trav_a->pro = trav_b;
				b++;
				trav_b = trav_b->prev;	
			}
		}
		trav_a = trav_a->prev;
		a++;
	}
}


static void	assign_pre_node(t_info *s)
{
	t_dll *trav_a;
	t_dll *trav_b;
	int	a;
	int b;
	
	a = 0;
	trav_a = s->a;
	trav_b = s->a->next;
	while (a < s->a_len)
	{
		b = 0;
		while (b < s->a_len)
		{
			if (trav_a->value != 0)
			{
				if (trav_a->value == trav_b->value + 1)
					trav_a->pre = trav_b;
				b++;
				trav_b = trav_b->next;	
			}
			else
			{
				if (trav_b->value == s->a_len - 1)
					trav_a->pre = trav_b;
				b++;
				trav_b = trav_b->next;	
			}
		}
		trav_a = trav_a->next;
		a++;
	}
}



static void	assign_indexes_to_labels(t_dll **tail)
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
				trav->value = j;
				break ;
			}
			j++;
		}
		i++;
	}



}









void	ft_init_stack_a(t_info *s, int argc, char *argv[])
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
		new->cost = 998;
		new->label = ft_atoi(argv[a]);
		new->next = new;
		new->prev = new;
		new->cost_rev = 998;
		//new->cost_sam = 998;
		//new->cost_swp = 998;
		new->cost_rot = 998;
		new->cost_opo_srot_drev = 998;
		new->cost_opo_srev_drot = 998;
		new->move_rev = false;
		new->move_rot = false;
		new->move_opo_srot_drev = false;
		new->move_opo_srev_drot = false;

		//new->move_sam = false;
		//new->move_swp = false;		


		ft_dclstadd_back(&(s->a), new);
		a++;
	}
	s->a_len = ft_dclstsize(&(s->a));
	s->b_len = 0;
	s->t_len = s->a_len + s->b_len; 
	assign_indexes_to_labels(&(s->a));	
	assign_pre_node(s);
	assign_pro_node(s);
	s->debug_movecount = 0;

	
}
