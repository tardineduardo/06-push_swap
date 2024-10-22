/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:50:42 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/17 21:01:08 by eduribei         ###   ########.fr       */
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
	char		*stringz;
}				t_node;


void	ft_validate_args(int argc, char *argv[]);
void	ft_init_stack(t_dlist **stack, int argc, char *argv[]);


//moves
void ra(t_dlist **taila);
void rb(t_dlist **tailb);
void rr(t_dlist **taila, t_dlist **tailb);
void rra(t_dlist **taila);
void rrb(t_dlist **tailb);
void rrr(t_dlist **taila, t_dlist **tailb);
#endif