/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:37:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/05/04 14:38:24 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*pointer;
	unsigned char	value;

	pointer = (unsigned char *)s;
	value = (unsigned char)c;
	a = 0;
	while (a < n)
	{
		if (pointer[a] == value)
			return (&pointer[a]);
		a++;
	}
	return (NULL);
}
