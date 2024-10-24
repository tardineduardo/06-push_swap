/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:27:23 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 15:42:56 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft.h"

// static	int ft_add_and_check_overflow()
// {
	
// }

// int	ft_atoi(const char *nptr)
// {
// 	int	nb;
// 	int last_digit;
// 	int	10_x_nb;
// 	int	sign;

// 	nb = 0;
// 	sign = 1;
// 	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
// 		nptr++;
// 	if (*nptr == '-' || *nptr == '+')
// 	{
// 		if (*nptr == '-')
// 			sign = -1;
// 		nptr++;
// 	}
// 	while (*nptr >= '0' && *nptr <= '9')
// 	{
// 		last = *nptr - '0';
// 		if (__builtin_mul_overflow(nb, 10, &10_x_nb))
// 		{
// 	        perror("ft_atoi: overflow occurred!\n");
// 			exit ()
// 		}
// 		10_x_nb = nb * 10;
// 		nb = 10_x_nb + last_digit;
// 		nptr++;
// 	}
// 	return (nb * sign);
// }

