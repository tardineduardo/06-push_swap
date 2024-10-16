/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:14:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/13 21:53:51 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_validate_args(int argc, char *argv[])
{
	int	a;
	int	*all;

	all = malloc((argc - 1) * sizeof(int));

	a = 1;
	while (a < argc)
	{
		all[a] = ft_atoi(argv[a]);
		a++;
	}
USE IS NUMBER, ATOI NAO CHECA ERRO!

	return (0);
}
