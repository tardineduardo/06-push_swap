/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 21:10:56 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	ft_assign_indexes_to_labels(t_table *s)
{
	int		i;
	int		j;
	int		*sorted_labels;
	t_dll	*trav;

	sorted_labels = malloc(s->t_len * sizeof(int));
	if (!sorted_labels)
		ft_perror_exit("assinging indexes", errno);
	trav = s->a;
	i = 0;
	while (i < s->t_len)
	{
		trav = trav->next;
		sorted_labels[i] = trav->label;
		i++;
	}
	ft_sort_int_array_bubble(sorted_labels, s->t_len);
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
	free(sorted_labels);
}

void	ft_set_stack_table(t_table *s)
{
	s->a_len = ft_dclstsize(&(s->a));
	s->b_len = 0;
	s->t_len = s->a_len + s->b_len; 
	find_hi_lo_nodes(s);
}




void	ft_malloc_and_init_nodes(t_table *s, int argc, char *argv[])
{
	int		i;
	t_dll	*new;

	s->a = NULL;
	s->b = NULL;
	i = 1;
	while (i < argc)
	{
		new = malloc(sizeof(t_dll));
		if (!new)
		{
			ft_dclstclear_simple(&(s->a));
			ft_perror_exit("stack malloc", errno);
		}
		new->label = ft_atoi(argv[i]);
		ft_init_node_values(s, argc, argv);
		ft_dclstadd_back(&(s->a), new);
		i++;
	}
	return ;
}



void	ft_init_node_values(t_dll *new, int argc, char *argv[])
{
	new->next = new;
	new->prev = new;
	new->cost = 998;
	new->cost_rev = 998;
	new->cost_rot = 998;
	new->cost_opo_srot_drev = 998;
	new->cost_opo_srev_drot = 998;
	new->move_rev = false;
	new->move_rot = false;
	new->move_opo_srot_drev = false;
	new->move_opo_srev_drot = false;
	return ;
}

void	ft_init_stacks_and_table(t_table *s, int argc, char *argv[])
{
	ft_malloc_and_init_nodes(s, argc, argv);
	ft_setup_stack_table(s);
	ft_assign_indexes_to_labels(s);	
	return ;
}




//	assign_pre_node(s);
//	assign_pro_node(s);

// static void	assign_pro_node(t_table *s)
// {
// 	t_dll *trav_a;
// 	t_dll *trav_b;
// 	int	a;
// 	int b;
	
// 	a = 0;
// 	trav_a = s->a;
// 	trav_b = s->a->prev;
// 	while (a < s->a_len)
// 	{
// 		b = 0;
// 		while (b < s->a_len)
// 		{
// 			if (trav_a->value != s->a_len - 1)
// 			{
// 				if (trav_a->value == trav_b->value - 1)
// 					trav_a->pro = trav_b;
// 				b++;
// 				trav_b = trav_b->prev;
// 			}
// 			else
// 			{
// 				if (trav_b->value == 0)
// 					trav_a->pro = trav_b;
// 				b++;
// 				trav_b = trav_b->prev;	
// 			}
// 		}
// 		trav_a = trav_a->prev;
// 		a++;
// 	}
// }


// static void	assign_pre_node(t_table *s)
// {
// 	t_dll *trav_a;
// 	t_dll *trav_b;
// 	int	a;
// 	int b;
	
// 	a = 0;
// 	trav_a = s->a;
// 	trav_b = s->a->next;
// 	while (a < s->a_len)
// 	{
// 		b = 0;
// 		while (b < s->a_len)
// 		{
// 			if (trav_a->value != 0)
// 			{
// 				if (trav_a->value == trav_b->value + 1)
// 					trav_a->pre = trav_b;
// 				b++;
// 				trav_b = trav_b->next;	
// 			}
// 			else
// 			{
// 				if (trav_b->value == s->a_len - 1)
// 					trav_a->pre = trav_b;
// 				b++;
// 				trav_b = trav_b->next;	
// 			}
// 		}
// 		trav_a = trav_a->next;
// 		a++;
// 	}
// }