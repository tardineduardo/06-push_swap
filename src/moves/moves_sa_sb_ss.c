/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_sa_sb_ss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:23:04 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	swap(t_dll **tail, int llen)
{
	t_dll	*temp;
		
	if (llen == 0 || llen == 1)
		return (false);
	else if (llen == 2)
	{
			(*tail) = (*tail)->next;
			return (true);
	}
	else
	{
		temp = (*tail)->next;
		(*tail)->next = (*tail)->next->next;
		(*tail)->next->prev = (*tail);
		temp->next = temp->next->next;
		temp->prev = (*tail)->next;
		temp->prev->next = temp;
		temp->next->prev = temp;
	}
	return (true);
}

void	sa(t_info *s, int fd)
{
	if (swap(&(s->a), s->a_len) && !s->a_is_csortd)
	{
		ft_dprintf(fd, "sa\n"); s->debug_movecount++;
		update_sorted_status(s);
	}

}

void	sb(t_info *s, int fd)
{
	if (swap(&(s->b), s->b_len && !s->b_is_csortd))
	{
		ft_dprintf(fd, "sb\n"); s->debug_movecount++;
		update_sorted_status(s);
	}
}

void	ss(t_info *s, int fd)
{
	bool	sa;
	bool	sb;

	sa = false;
	sb = false;
	if (swap(&(s->a), s->a_len) && !s->a_is_csortd)
		sa = true;
	if (swap(&(s->b), s->b_len && !s->b_is_csortd))
		sb = true;
	if (sa && sb) {
		ft_dprintf(fd, "ss\n"); s->debug_movecount++;}
	else if (sa && !sb) {
		ft_dprintf(fd, "sa\n"); s->debug_movecount++;}
	else if (!sa && sb) {
		ft_dprintf(fd, "sb\n"); s->debug_movecount++;}
	update_sorted_status(s);
}
