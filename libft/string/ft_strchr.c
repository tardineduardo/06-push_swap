/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:48:44 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/13 16:04:13 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	while (*str != '\0' || a == '\0')
	{
		if (*str == a)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
