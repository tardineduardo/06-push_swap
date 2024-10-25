/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:50:42 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 21:48:50 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int			value;
}				t_node;

void	ft_validate_args(int argc, char *argv[]);
void	ft_init_stack(t_dlist **stack, int argc, char *argv[]);
void	ft_play_print(t_dlist **a, t_dlist **b);

//moves
void	ra(t_dlist **taila, int fd);
void	rb(t_dlist **tailb, int fd);
void	rr(t_dlist **taila, t_dlist **tailb, int fd);
void	sa(t_dlist **taila, int fd);
void	sb(t_dlist **tailb, int fd);
void	ss(t_dlist **taila, t_dlist **tailb, int fd);
void	rra(t_dlist **taila, int fd);
void	rrb(t_dlist **tailb, int fd);
void	rrr(t_dlist **taila, t_dlist **tailb, int fd);
void	pa(t_dlist **src, t_dlist **dest, int fd);
void	pb(t_dlist **src, t_dlist **dest, int fd);

#endif
