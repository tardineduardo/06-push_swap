/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/05 20:52:28 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int debug_movecount = 0;

void debug_status(t_info *s)
{
	//ft_play_print_values(&(s->a), &(s->b));
	if (gridlock(s))
	 	ft_printf("GRIDLOCK\n");
	if ((s->a_csort))
		ft_printf("a sorted\n");
	if ((s->b_csort))
		ft_printf("b sorted\n");
	ft_printf("%i\n", s->debug_movecount);
}


int	main(int argc, char *argv[])
{
	t_info	*s;

	s = malloc(sizeof(t_info));
	ft_validate_args(argc, argv);
	ft_init_stacks(s, argc, argv);
	//	ft_play(s);
	split_by_order(s);
	// even_nodes_per_stack(s);
	find_hi_lo_nodes(s);
	//ft_play_print_values(&(s->a), &(s->b));
	while (1)
	{
		update_sorted_status(s);
		mid_sorted_status(s);

		if ((s->a_csort))
			break ;
		if ((s->b_csort))
			break ;			
		if (swapping_works(s))
		{
			ft_printf("SWAPPING NORMAL");
			//ft_play_print_values(&(s->a), &(s->b));
			continue;
		}
		else if (swapping_back_works(s))
		{
			ft_printf("SWAPPING REVERSO");
			//ft_play_print_values(&(s->a), &(s->b));
			continue;
		}
		else
		{
			calculate_all_costs3(s);
			//ft_play_print_values(&(s->a), &(s->b));
			move(s);
		}
	//ft_play_print_values(&(s->a), &(s->b));
	}

	debug_status(s);
}

	// ft_play(s);
	//split_by_alternate_order(s);
