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

static bool ft_check_int_normal(t_dlist **tail, int offset)
{
	int 	curr;
	int		next;
	t_dlist *trav;
	int		len;

	len = ft_dclstsize(tail);
	trav = (*tail)->next;
	while(len > 1)
	{
		curr = *(int *)((char *)trav->content + offset);
		next = *(int *)((char *)trav->next->content + offset);
		if (curr > next)
			return (false);
		trav = trav->next;
		len--;
	}
	return (true);
}

static bool ft_check_int_reverse(t_dlist **tail, int offset)
{
	int 	curr;
	int		next;
	t_dlist *trav;
	int		len;

	len = ft_dclstsize(tail);
	trav = (*tail)->next;
	while(len > 1)
	{
		curr = *(int *)((char *)trav->content + offset);
		next = *(int *)((char *)trav->next->content + offset);
		if (curr < next)
			return (false);
		trav = trav->next;
		len--;
	}
	return (true);
}

bool ft_dclst_list_sortd(t_dlist **tail, char *type, char mode, int offset)
{
	if (ft_strcmp(type, "int") == 0)
		if (mode == 'n')
			return (ft_check_int_normal(tail, offset));
		else if (mode == 'r')
			return (ft_check_int_reverse(tail, offset));
		else
			ft_perror_exit("is_stack_sorted: invalid mode", 1); /// IMPROVE ERROR
	else
		ft_perror_exit("is_stack_sorted: invalid type", 1);  /// IMPROVE ERROR
	return (false);
}
