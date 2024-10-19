/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:49:43 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/18 15:34:55 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstrarr_fd(char **array, int fd)
{
	int	a;

	a = 0;
	while (array[a] != NULL)
	{
		ft_putstr_fd("[", fd);
		ft_putnbr_fd(a, fd);
		ft_putstr_fd("] ", fd);
		ft_putstr_fd(array[a], fd);
		ft_putstr_fd("\n", fd);
		a++;
	}
	ft_putstr_fd("\n", fd);
}
