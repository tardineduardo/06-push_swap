/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:17:20 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/13 16:02:52 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		write(fd, s, 1);
		count++;
		s++;
	}
	return (count);
}
