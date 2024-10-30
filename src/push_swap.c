/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/28 20:52:38 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int debug_movecount = 0;

int	main(int argc, char *argv[])
{
	t_info	*s;

	s = malloc(sizeof(t_info));

	//ft_validate_args(argc, argv);	

	ft_init_stacks(s, argc, argv);

	//ft_play(s);

	//init_stack_debug(s);
	
	ft_play_print_values(&(s->a), &(s->b));

	//even_nodes_per_stack(s);

	ft_play_print_values(&(s->a), &(s->b));

	solve(s);

	ft_play_print_values(&(s->a), &(s->b));

	ft_printf("%i\n", s->debug_movecount);
}
