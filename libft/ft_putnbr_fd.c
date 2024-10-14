/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:17:48 by eduribei          #+#    #+#             */
/*   Updated: 2024/05/22 10:28:02 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_get_digits(char *number, unsigned int abs_n, int n)
{
	int	a;

	a = 0;
	while (abs_n >= 1)
	{
		number[a] = (abs_n % 10) + 48;
		abs_n = abs_n / 10;
		a++;
	}
	if (n < 0)
		number[a] = '-';
}

void	ft_putnbr_fd(int n, int fd)
{
	int				print_len;
	unsigned int	abs_n;
	char			number[12];

	ft_bzero(number, 12);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n < 0)
		abs_n = (unsigned int)(-n);
	else
		abs_n = n;
	ft_get_digits(number, abs_n, n);
	print_len = ft_strlen(number) - 1;
	while (print_len >= 0)
	{
		write(fd, &number[print_len], 1);
		print_len--;
	}
}
