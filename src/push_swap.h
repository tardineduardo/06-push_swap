/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:50:42 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 19:30:03 by eduribei         ###   ########.fr       */
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
	int			t_len;
	bool		a_is_clock_sorted;
	bool		b_is_clock_sorted;
	bool		a_partially_sorted;
	bool		b_partially_sorted;
	char		dst_name;
	t_dll		*hi_a;
	t_dll		*lo_a;
	t_dll		*hi_b;
	t_dll		*lo_b;
}				t_table;

//main
void	ft_malloc_and_init_nodes(t_table *s, int argc, char *argv[]);
void	ft_validate_args(int argc, char *argv[]);
void	ft_init_stacks_and_table(t_table *s, int argc, char *argv[]);
void	ft_init_stack_b(t_table *s);
void	ft_set_cost_and_move(int dist_s_head, int dist_d_head, t_dll *node);

void	move_opo_srot_drev(t_table *s, t_dll *lowest);
void	move_opo_srev_drot(t_table *s, t_dll *lowest);
void	move_node_to_top(t_table *s, t_dll **stack, t_dll *node);
void	move_rev(t_table *s, t_dll *lowest);
void	move_rot(t_table *s, t_dll *lowest);

void	set_cross_costs_to_locked(t_dll *node);
void	reset_costs(t_dll *node);

//algo
void	push_lower_values_to_b(t_table *s);
void	calculate_all_costs(t_table *s);
void	update_sorted_status(t_table *s);
void	move_node_to_top(t_table *s, t_dll **stack, t_dll *node);
void	calculate_costs_in_stack_a(t_table *s);
void	calculate_costs_in_stack_b(t_table *s);

void	move(t_table *s);

bool	swapping_back_works(t_table *s);
void	update_partially_sorted_status(t_table *s);
void	choose_and_move_node(t_table *s);



//costs
void	calculate_all_costs2(t_table *s);
void	calculate_opo_costs2(t_table *s, char dest_stack);
void	calculate_rev_costs2(t_table *s, char stack);
void	calculate_rot_costs2(t_table *s, char dest_stack);
void	calculate_sam_costs2(t_table *s, char stack);
void	calculate_swp_costs2(t_table *s, char stack);

//moves
void	ra(t_table *s, int fd);
void	rr(t_table *s, int fd);
void	rb(t_table *s, int fd);
void	sa(t_table *s, int fd);
void	sb(t_table *s, int fd);
void	ss(t_table *s, int fd);
void	pa(t_table *s, int fd);
void	pb(t_table *s, int fd);
void	rra(t_table *s, int fd);
void	rrb(t_table *s, int fd);
void	rrr(t_table *s, int fd);

//debug
void	init_stack_debug(t_table *s);

//play
void	ft_play_print_labels(t_dll **a, t_dll **b);
void	ft_play_print_values(t_dll **a, t_dll **b);
void	ft_play(t_table *s);


#endif
