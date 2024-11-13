/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:50:42 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/13 16:23:21 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# ifndef OPT
#  define OPT 20
# endif

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
	bool		already_sorted;
	bool		cheap_a_locked;
	bool		block_swap;
	char		dst_name;
	char		mode;
	t_dll		*hi_a;
	t_dll		*lo_a;
	t_dll		*hi_b;
	t_dll		*lo_b;
	t_dll		*cheap_in_a;
}				t_table;

//main
void	ft_validate_args(int argc, char *argv[]);
void	ft_init_stacks_and_table(t_table *s, int argc, char *argv[]);

//algo_high
void	ft_update_partially_sorted_status(t_table *s);
void	ft_calculate_cost_a_to_b(t_table *s, t_dll *node);
void	ft_init_stack_b(t_table *s);
void	ft_calculate_all_costs(t_table *s);
void	ft_move_node_to_top(t_table *s, t_dll **stack, t_dll *node);
void	ft_find_hi_lo_nodes(t_table *s);

//algo_low
void	ft_low_assign_procedent_node(t_table *s);
void	ft_low_init_stack_b(t_table *s);
void	ft_low_try_swapping(t_table *s);

//moves_algo
void	ft_move_rot(t_table *s, t_dll *lowest);
void	ft_move_rev(t_table *s, t_dll *lowest);
void	ft_move_opo_srot_drev(t_table *s, t_dll *lowest);
void	ft_move_opo_srev_drot(t_table *s, t_dll *lowest);
void	ft_move(t_table *s);

//moves
void	ft_ra(t_table *s, int fd);
void	ft_rr(t_table *s, int fd);
void	ft_rb(t_table *s, int fd);
void	ft_sa(t_table *s, int fd);
void	ft_sb(t_table *s, int fd);
void	ft_ss(t_table *s, int fd);
void	ft_pa(t_table *s, int fd);
void	ft_pb(t_table *s, int fd);
void	ft_rra(t_table *s, int fd);
void	ft_rrb(t_table *s, int fd);
void	ft_rrr(t_table *s, int fd);

#endif
