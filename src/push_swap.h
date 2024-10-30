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
	bool		a_is_csortd;
	bool		b_is_csortd;
	t_dll		*cheapest_node;
	t_dll		*cheapest_stack;
	t_dll		*src_stack;
	t_dll		*dst_stack;	
	char		dst_name;
	char		src_name;
	int			debug_movecount;
}				t_info;


void	ft_validate_args(int argc, char *argv[]);
void	ft_init_stacks(t_info *s, int argc, char *argv[]);

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

void	ft_play(t_info *s);
void	solve(t_info *s);
void	even_nodes_per_stack(t_info *s);
void	calculate_all_costs(t_info *s);
void	find_lowest_cost(t_info *s);
void	move_node_to_top_source(t_info *s, t_dll *node);
void	move_node_to_top_dest(t_info *s, t_dll *node);
void	move_cheapest_node(t_info *s);
void	repostion_dst_stack(t_info *s, t_dll *node);
void	ft_play_print_labels(t_dll **a, t_dll **b);
void	ft_play_print_values(t_dll **a, t_dll **b);
bool	swapping_works(t_info *s);
void	update_sorted_status(t_info *s);



//debug
void	init_stack_debug(t_info *s);

#endif
