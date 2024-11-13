/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/12 20:22:09 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
