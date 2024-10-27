/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_is_list_sorted.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:55:08 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/26 20:55:42 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static bool ft_check_int_normal(t_dlist **tail, char mode, int offset)
{
	int 	curr;
	int		next;
	t_dlist *trav;

	while(trav->next->next != *tail)
	{
		curr = *(int *)((char *)trav->content + offset);
		next = *(int *)((char *)trav->next->content + offset);
		if (curr > next)
			return (false);
	}
	return (true);
}

static bool ft_check_int_normal(t_dlist **tail, char mode, int offset)
{
	int 	curr;
	int		next;
	t_dlist *trav;

	while(trav->next->next != *tail)
	{
		curr = *(int *)((char *)trav->content + offset);
		next = *(int *)((char *)trav->next->content + offset);
		if (curr < next)
			return (false);
	}
	return (true);
}

bool ft_dclst_is_list_sorted(t_dlist **tail, char *type, char mode, int offset)
{
	int 	curr;
	int		next;
	t_dlist *trav;

	trav = *tail;
	if (ft_strcmp(type, "int") == 0)
		if (mode == 'n')
			return (ft_check_int_normal(tail, mode, offset));
		else if (mode == 'r')
			return (ft_check_int_reverse(tail, mode, offset));
		else
			ft_perror_exit("is_stack_sorted: invalid mode", 1);
	else
		ft_perror_exit("is_stack_sorted: invalid type", 1);
}
