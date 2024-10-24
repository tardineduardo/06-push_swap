/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:39:39 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 21:36:54 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move(char *cmd, t_dlist **a, t_dlist **b)
{
	int moves = open("moves.txt", O_WRONLY | O_APPEND | O_CREAT, 0664);
	if(ft_strcmp(cmd, "pa") == 0)
		pa(a, b, moves);
	else if(ft_strcmp(cmd, "pb") == 0)
		pb(b, a, moves);
	else if(ft_strcmp(cmd, "sa") == 0)
		sa(a, moves);
	else if(ft_strcmp(cmd, "sb") == 0)
		sb(b, moves);
	else if(ft_strcmp(cmd, "ss") == 0)
		ss(a, b, moves);
	else if(ft_strcmp(cmd, "ra") == 0)
		ra(a, moves);
	else if(ft_strcmp(cmd, "rb") == 0)
		rb(b, moves);
	else if(ft_strcmp(cmd, "rr") == 0)
		rr(a, b, moves);
	else if(ft_strcmp(cmd, "rra") == 0)
		rra(a, moves);
	else if(ft_strcmp(cmd, "rrb") == 0)
		rrb(b, moves);
	else if(ft_strcmp(cmd, "rrr") == 0)
		rrr(a, b, moves);
	close(moves);
}

int	main(int argc, char *argv[])
{
	t_dlist	*stacka;
	t_dlist	*stackb;
	char	cmd[4];
	int		visual;
	int		moves;

	ft_validate_args(argc, argv);	
	stacka = NULL;
	stackb = NULL;
	ft_init_stack(&stacka, argc, argv);

	cmd[0] = 0;

	moves = open("moves.txt", O_WRONLY | O_TRUNC | O_CREAT, 0664);
	visual = open("visual.txt", O_WRONLY | O_TRUNC | O_CREAT, 0664);
	close(visual);
	close(moves);	

	while (ft_strcmp(cmd, "q") != 0)
	{
		visual = open("visual.txt", O_WRONLY | O_TRUNC | O_CREAT, 0664);
		ft_play_print(&stacka, &stackb, visual);
		close(visual);
		ft_printf("type a command: ");
		scanf("%3s", cmd);
		move(cmd, &stacka, &stackb);
		fflush(stdin);
		//system("clear");
	}
	close(visual);
	return (0);
}
