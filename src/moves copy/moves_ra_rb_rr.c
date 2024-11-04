/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ra_rb_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:31:26 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 17:05:44 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_info *s, int fd)
{
	if (s->a_len == 0 || s->a_len == 1)
		return ;
	s->a = s->a->prev;
	ft_dprintf(fd, "ra\n");
	s->debug_movecount++;
}

void	rb(t_info *s, int fd)
{
	if (s->b_len == 0 || s->b_len == 1)
		return ;
	s->b = s->b->prev;
	ft_dprintf(fd, "rb\n");
	s->debug_movecount++;
}

void	rr(t_info *s, int fd)
{
	bool	a;
	bool	b;

	a = false;
	b = false;
	if (s->a_len > 1)
	{
		s->a = s->a->prev;
		a = true;
	}
	if (s->b_len > 1)
	{
		s->b = s->b->prev;
		b = true;
	}
	if (a && b) {
		ft_dprintf(fd, "rr\n"); s->debug_movecount++;}
	else if (a && !b) {
		ft_dprintf(fd, "ra\n"); s->debug_movecount++;}
	else if (!a && b) {
		ft_dprintf(fd, "rb\n"); s->debug_movecount++;}
}
