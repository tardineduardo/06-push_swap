/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:04:55 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/02 16:39:16 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(int total, ...)
{
	va_list	args;
	void	*ptr;
	int		a;

	va_start(args, total);
	a = 0;
	while (a < total)
	{
		ptr = va_arg(args, void *);
		if (ptr)
			free(ptr);
		a++;
	}
	va_end(args);
}
