/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:50:42 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/10 21:04:18 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# ifndef OPT
#  define OPT 25
# endif


#ifndef PRINT
# define PRINT do { ft_play_print_values(&(s->a), &(s->b)); } while (0)
#endif
	
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
void	ft_init_stack_b(t_table *s);

//costs
void	ft_reset_costs(t_table *s, t_dll *node);
void	update_sorted_status(t_table *s);
void	update_partially_sorted_status(t_table *s);
void	calculate_cost_b_to_a(t_table *s, t_dll *node);
void	calculate_cost_a_to_b(t_table *s, t_dll *node);

//other
void	move_rot(t_table *s, t_dll *lowest);
void	move_rev(t_table *s, t_dll *lowest);
void	move_opo_srot_drev(t_table *s, t_dll *lowest);
void	move_opo_srev_drot(t_table *s, t_dll *lowest);
void	move(t_table *s);
bool	swapping_works(t_table *s);
bool	swapping_back_works(t_table *s);


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

//-------------------------------------------------------------------
//algo
void	calculate_all_costs(t_table *s);
t_dll	*find_lowest_cost(t_dll **tail);
bool	swapping_works(t_table *s);
void	move_node_to_top(t_table *s, t_dll **stack, t_dll *node);
void	find_hi_lo_nodes(t_table *s);
void	calculate_all_costs(t_table *s);
void	partially_sorted_status(t_table *s);
void	select_node_to_move(t_table *s);

//play
void	ft_play_print_labels(t_dll **a, t_dll **b);
void	ft_play_print_values(t_dll **a, t_dll **b);

#endif
