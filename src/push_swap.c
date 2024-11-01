/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/30 18:39:47 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int debug_movecount = 0;


int	main(int argc, char *argv[])
{
	t_info	*s;

	s = malloc(sizeof(t_info));
	ft_validate_args(argc, argv);
	ft_init_stacks(s, argc, argv);
//	//ft_play_print_values(&(s->a), &(s->b));
	push_lower_values_to_b(s);
	//sort_highest_values(s);
	//push_lower_values_to_a(s);


	ft_printf("%i\n", s->debug_movecount);
}





	// ft_play(s);
