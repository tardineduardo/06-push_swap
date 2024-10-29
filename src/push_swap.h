/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:50:42 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/28 20:54:26 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_info
{
	t_dll		*a;
	t_dll		*b;
	int			a_len;
	int			b_len;
}				t_info;

void	ft_validate_args(int argc, char *argv[]);
void	ft_init_stacks(t_info *s, int argc, char *argv[]);

//moves
void	ra(t_dll **tail_a, int fd);
void	rb(t_dll **tail_b, int fd);
void	rr(t_dll **tail_a, t_dll **tail_b, int fd);
void	sa(t_dll **tail_a, int fd);
void	sb(t_dll **tail_b, int fd);
void	ss(t_dll **tail_a, t_dll **tail_b, int fd);
void	rra(t_dll **tail_a, int fd);
void	rrb(t_dll **tail_b, int fd);
void	rrr(t_dll **tail_a, t_dll **tail_b, int fd);
void	pa(t_dll **src, t_dll **dest, int fd);
void	pb(t_dll **src, t_dll **dest, int fd);

void	solve(t_dll **stack_a, t_dll **stack_b);
void	move_node_to_top(t_dll **stack, t_dll *node);
void	ft_play_print(t_dll **a, t_dll **b);

//debug
void	init_stack_debug(t_info *s);

#endif
