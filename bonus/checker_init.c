/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/14 15:47:36 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_init_node_values(t_dll *new)
{
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
			ft_perror_exit("stack malloc", errno);
		}
		ft_init_node_values(new);
		new->label = ft_atoi(argv[a]);
		new->next = new;
		new->prev = new;
		ft_dclstadd_back(&(s->a), new);
		a++;
	}
}

void	ft_checker_init(t_table *s, int argc, char *argv[])
{
	ft_malloc_and_init_nodes(s, argc, argv);
	s->a_len = ft_dclstsize(&(s->a));
	s->b_len = 0;
	s->t_len = s->a_len + s->b_len;
	return ;
}
