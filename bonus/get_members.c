/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_members.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:33:09 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/14 19:31:21 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*get_label(void *node)
{
	t_dll	*n;

	n = (t_dll *)node;
	return (&(n->label));
}

void	*get_value(void *node)
{
	t_dll	*n;

	n = (t_dll *)node;
	return (&(n->value));
}
