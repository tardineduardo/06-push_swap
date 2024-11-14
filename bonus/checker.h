/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:50:42 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/14 13:37:55 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct s_info
{
	t_dll		*a;
	t_dll		*b;
	int			a_len;
	int			b_len;
	int			t_len;
	bool		is_sorted;
}				t_table;

//main
void	ft_checker_validate(int argc, char *argv[]);
void	ft_checker_init(t_table *s, int argc, char *argv[]);
void*	get_label(void* node); 
void*	get_value(void* node);

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

