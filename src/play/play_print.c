/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:41:34 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/28 15:43:49 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_a(t_dll **a)
{
	int i;
	
	i = ((t_nd *)((*a)->content))->val;
	ft_printf(RED "\t\t\t\t+-------+\n" RESET);
	ft_printf(RED "\t\t\t\t|\t" RESET "%i" RED "\t|\n" RESET, i);
	ft_printf(RED "\t\t\t\t+-------+\n" RESET);
}

void	put_b(t_dll **b)
{
	int i;
	
	i = ((t_nd *)((*b)->content))->val;
	ft_printf(YELLOW "\t\t\t\t\t\t\t+-------+\n" RESET);
	ft_printf(YELLOW "\t\t\t\t\t\t\t|\t" RESET "%i" YELLOW "\t|\n" RESET, i);
	ft_printf(YELLOW "\t\t\t\t\t\t\t+-------+\n" RESET);
}

void	put_ab(t_dll **a, t_dll **b)
{
	int i;
	int j;

	i = ((t_nd *)((*a)->content))->val;
	j = ((t_nd *)((*b)->content))->val;
	ft_printf(RED "\t\t\t\t+-------+" YELLOW "\t+-------+\n" RESET);
	ft_printf(RED "\t\t\t\t|\t" RESET "%i" RED "\t|" YELLOW "\t|\t" RESET "%i" YELLOW "\t|\n", i, j);
	ft_printf(RED "\t\t\t\t+-------+" YELLOW "\t+-------+\n" RESET);
}

void	ft_play_print(t_dll **a, t_dll **b)
{
	int height;
	t_dll *trav_a;
	t_dll *trav_b;
	t_dll *space_a;
	t_dll *space_b;

	int	index_a;
	int	index_b;

	index_a = 0;
	index_b = 0;

	height = ft_dclstsize(a) + ft_dclstsize(b); 

//	ft_printf("\n");
	while (height > 0)
	{
		space_a = ft_dclsttrav_to_index(a, height - 1);
		space_b = ft_dclsttrav_to_index(b, height - 1);

		if (space_a)
		{
			trav_a = ft_dclsttrav_to_index(a, index_a);
			index_a++;
		}
		if (space_b)
		{
			trav_b = ft_dclsttrav_to_index(b, index_b);
			index_b++;
		}
		if (!space_a && !space_b)
			ft_printf("\n\n\n");
		else if (space_a && space_b)
			put_ab(&trav_a, &trav_b);			
		else if (space_a && !space_b)
			put_a(&trav_a);
		else if (!space_a && space_b)
			put_b(&trav_b);
	height--;
	}
	ft_printf("____________________________________________________\n");
	ft_printf("\t\t\t\t stack a\t stack b\n");


	ft_printf("\n");

}


