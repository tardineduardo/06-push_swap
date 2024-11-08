/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:50:42 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/08 17:47:02 by eduribei         ###   ########.fr       */
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
	bool		block_swap;	
	char		dst_name;
	t_dll		*dst_s;
	t_dll		*last_moved;
	t_dll		*hi_a;
	t_dll		*lo_a;
	t_dll		*hi_b;
	t_dll		*lo_b;
	int			debug_movecount;
}				t_info;

//main
void	ft_validate_args(int argc, char *argv[]);
void	ft_init_stack_a(t_info *s, int argc, char *argv[]);

//algo
void	push_lower_values_to_b(t_info *s);
void	calculate_all_costs(t_info *s);
t_dll	*find_lowest_cost(t_dll **tail);
bool	swapping_works(t_info *s);
void	update_sorted_status(t_info *s);
void	even_nodes_per_stack(t_info *s);
void	move_node_to_top(t_info *s, t_dll **stack, t_dll *node);
void	make_move(t_info *s);
bool	all_locked(t_info *s);
void	split_by_order(t_info *s);
void	find_hi_lo_nodes(t_info *s);
void	calculate_all_costs(t_info *s);
void	move(t_info *s);
void	update_split1(t_info *s);
bool	gridlock(t_info *s);
void 	unlock(t_info *s);
bool	swapping_back_works(t_info *s);
void	mid_sorted_status(t_info *s);
void	select_node_to_move(t_info *s);
void	send_two_lower_values_to_stack_b(t_info *s);


//costs
void	calculate_all_costs2(t_info *s);
void	calculate_opo_costs2(t_info *s, char dest_stack);
void	calculate_rev_costs2(t_info *s, char stack);
void	calculate_rot_costs2(t_info *s, char dest_stack);
void	calculate_sam_costs2(t_info *s, char stack);
void	calculate_swp_costs2(t_info *s, char stack);

//moves
void	ra(t_info *s, int fd);
void	rr(t_info *s, int fd);
void	rb(t_info *s, int fd);
void	sa(t_info *s, int fd);
void	sb(t_info *s, int fd);
void	ss(t_info *s, int fd);
void	pa(t_info *s, int fd);
void	pb(t_info *s, int fd);
void	rra(t_info *s, int fd);
void	rrb(t_info *s, int fd);
void	rrr(t_info *s, int fd);

//debug
void	init_stack_debug(t_info *s);

//play
void	ft_play_print_labels(t_dll **a, t_dll **b);
void	ft_play_print_values(t_dll **a, t_dll **b);
void	ft_play(t_info *s);


#endif
