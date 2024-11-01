/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:39:39 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BRIGHT_GREEN "\033[92m"

void move(char *cmd, t_info *s)
{
	int moves = open("moves.txt", O_WRONLY | O_APPEND | O_CREAT, 0664);
	if(ft_strcmp(cmd, "pa") == 0)
		pa(s, moves);
	else if(ft_strcmp(cmd, "pb") == 0)
		pb(s, moves);
	else if(ft_strcmp(cmd, "sa") == 0)
		sa(s, moves);
	else if(ft_strcmp(cmd, "sb") == 0)
		sb(s, moves);
	else if(ft_strcmp(cmd, "ss") == 0)
		ss(s, moves);
	else if(ft_strcmp(cmd, "ra") == 0)
		ra(s, moves);
	else if(ft_strcmp(cmd, "rb") == 0)
		rb(s, moves);
	else if(ft_strcmp(cmd, "rr") == 0)
		rr(s, moves);
	else if(ft_strcmp(cmd, "rra") == 0)
		rra(s, moves);
	else if(ft_strcmp(cmd, "rrb") == 0)
		rrb(s, moves);
	else if(ft_strcmp(cmd, "rrr") == 0)
		rrr(s, moves);
	close(moves);
}

void	ft_play(t_info *s)
{
	char	cmd[4];
	int		moves;

	//ft_validate_args(argc, argv);	

	cmd[0] = 0;
	moves = open("moves.txt", O_WRONLY | O_TRUNC | O_CREAT, 0664);
	close(moves);	
	while (ft_strcmp(cmd, "q") != 0)
	{
		system("clear");
		calculate_all_costs(s);
		//ft_play_print_values(&(s->a), &(s->b));
		ft_printf("( " GREEN "pa pb " CYAN "sa sb ss " MAGENTA "ra rb rr " BRIGHT_GREEN "rra rrb rrr " RESET ") (\"q\" for quit)\n\n");
		ft_printf("type a command: ");
		scanf("%3s", cmd);
		move(cmd, s);
		fflush(stdin);
		system("clear");
	}
}
