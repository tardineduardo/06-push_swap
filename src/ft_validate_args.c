/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:12:52 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 16:59:53 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static bool ft_values_are_integer_only(int argc, char *argv[])
{
	int	a;
	int b;

	a = 1;
	while (a < argc)
	{
		b = 0;
		while (ft_isspace(argv[a][b]))
			b++;
		if (argv[a][b] == '-' || argv[a][b] == '+')
			b++;
		while ((argv[a][b]) != 0)
		{
			if (!ft_isdigit(argv[a][b]))
				return (false);
			b++;
		}
		a++;
	}
	return (true);
}
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
static bool ft_values_are_distinct_and_size_int(int argc, char *argv[])
{
	size_t	a;
	size_t	b;
	long long int	set[argc - 1];

	//ft_printf("%i\n", sizeof(long long int));

	//printf("%llu\n", LLONG_MAX);	
	a = 0;
	while (a < argc - 1)
	{
		set[a] = ft_atoi(argv[a + 1]);
		if (set[a] > INT_MAX || set[a] < INT_MIN)
			return (false);
		b = 0;
		while (b < a)
		{
			if (set[b] == set[a])
				return (false);
			b++;
		}
	a++;
	}
	return (true);
}

static bool ft_values_are_sorted(int argc, char *argv[])
{
	int	a;
	int	curr;
	int	next;
	int	count;

	a = 1;
	count = 0;
	while (a < argc - 1)
	{
		curr = ft_atoi(argv[a]);
		next = ft_atoi(argv[a + 1]);
		if (curr > next)
			count++;
		a++;
	}
	if (count == 0)
		return (true);
	return (false);
}

void	ft_validate_args(int argc, char *argv[])
{
	if (argc < 3)
		ft_error_exit("errorz\n", 1, STDERR_FILENO);
	else if (!ft_values_are_integer_only(argc, argv))
		ft_error_exit("Error - not integers\n", 1, STDERR_FILENO);
	else if (!ft_values_are_distinct_and_size_int(argc, argv))
		ft_error_exit("Error - repeated values\n", 1, STDERR_FILENO);
	else if (ft_values_are_sorted(argc, argv))
		ft_error_exit("Error - already sorted\n", 1, STDERR_FILENO);
}
