/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:50:42 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/26 20:10:45 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	int			label;
	int			val;
}				t_node;

void	ft_validate_args(int argc, char *argv[]);
void	ft_init_stack(t_dlist **stack, int argc, char *argv[]);

//moves
void	ra(t_dlist **tail_a, int fd);
void	rb(t_dlist **tail_b, int fd);
void	rr(t_dlist **tail_a, t_dlist **tail_b, int fd);
void	sa(t_dlist **tail_a, int fd);
void	sb(t_dlist **tail_b, int fd);
void	ss(t_dlist **tail_a, t_dlist **tail_b, int fd);
void	rra(t_dlist **tail_a, int fd);
void	rrb(t_dlist **tail_b, int fd);
void	rrr(t_dlist **tail_a, t_dlist **tail_b, int fd);
void	pa(t_dlist **src, t_dlist **dest, int fd);
void	pb(t_dlist **src, t_dlist **dest, int fd);

//debug
void init_stack_debug(t_dlist **stack);


#endif
