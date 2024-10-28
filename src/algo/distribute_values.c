/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:44:52 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 21:13:27 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_dll	*smallest(t_dll *op1, t_dll *op2)
{
	int op1_val;
	int op2_val;

	op1_val = ((t_nd *)((op1)->content))->val;
	op2_val = ((t_nd *)((op2)->content))->val;
	if (op1_val > op2_val)
		return (op1);
	return (op2);
}
static t_dll	*best_fit_in_b(t_dll **t_b, t_dll *op1, t_dll *op2)
{
	int b_last;
	int b_frst;
	bool op1_bool;
	bool op2_bool;

	op1_bool = false;
	op2_bool = false;
	b_last = ((t_nd *)((*t_b)->content))->val;
	b_frst = ((t_nd *)((*t_b)->next->content))->val;
	
	if (((t_nd *)((op1)->content))->val < b_frst && ((t_nd *)((op1)->content))->val > b_last)
		op1_bool = true;
	if (((t_nd *)((op2)->content))->val < b_frst && ((t_nd *)((op2)->content))->val > b_last)
		op2_bool = true;

	if (op1_bool && !op2_bool)
		return (op1);
	else if (!op1_bool && op2_bool)
		return (op2);
	return (smallest(op1, op2));
}
// por enquanto tirei o stacka do tirbreak, mas deve voltar
static t_dll	*ft_tiebk(t_dll **t_b, t_dll *op1, t_dll *op2)
{
	int	bsize;
	int b_last;
	int b_frst;

	b_last = ((t_nd *)((*t_b)->content))->val;
	b_frst = ((t_nd *)((*t_b)->next->content))->val;
	bsize = ft_dclstsize(t_b);
	if (bsize < 2)
		return (smallest(op1, op2));
	return (best_fit_in_b(t_b, op1, op2));
}

static t_dll	*best_push_op(t_dll **t_a, t_dll **t_b)
{
	t_dll		*trav_fwd;
	t_dll		*trav_bck;
	t_dll		*op1;
	t_dll		*op2;
	int 		a_len;
	int			i;
	a_len = ft_dclstsize(t_a);
	trav_fwd = (*t_a)->next;
	trav_bck = (*t_a);
	
	i = 0;
	while (i <= a_len / 2) 
	{
		op1 = NULL;
		op2 = NULL;
		if (((t_nd *)(trav_fwd->content))->val < (a_len/2))
			op1 = trav_fwd;
		if (((t_nd *)(trav_bck->content))->val < (a_len/2))		
			op2 = trav_bck;	
		if (op1 && !op2)
			return (op1);
		else if (!op1 && op2)
			return (op2);
		if (op1 && op2)
			return (ft_tiebk(t_b, op1, op2));
		i++;
		trav_fwd = trav_fwd->next;
		trav_bck = trav_fwd->prev;
	}
	return (NULL);
}

void	distribute_values(t_dll **stack_a, t_dll **stack_b)
{
	t_dll	*best_opt;
	int		sa_len;
	int		sb_len;
	int		half;

	ft_printf("INICIO\n");
	ft_play_print(stack_a, stack_b);


	// ft_debug_print_dclist(stack_a, "int", offsetof(t_nd, val), 1);
	// ft_debug_print_dclist(stack_b, "int", offsetof(t_nd, val), 1);

	sa_len = ft_dclstsize(stack_a);
	sb_len = 0;
	half = sa_len / 2; 
	while (sa_len > half)
	{
		best_opt = best_push_op(stack_a, stack_b);
		ft_printf("best value to push is >>>> %i\n\n", ((t_nd *)((best_opt)->content))->val);
		move_node_to_top(stack_a, best_opt);
		pb(stack_a, stack_b, 1);
		ft_play_print(stack_a, stack_b);

		// ft_debug_print_dclist(stack_a, "int", offsetof(t_nd, label), 1);
		// ft_debug_print_dclist(stack_b, "int", offsetof(t_nd, label), 1);
		sa_len--;
	}
}
