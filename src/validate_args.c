/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:12:52 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/12 20:46:04 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static bool	ft_labels_are_integer_only(int argc, char *argv[])
{
	int	a;
	int	b;

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

static bool	ft_labels_are_distinct_and_size_int(int argc, char *argv[])
{
	long long int	a;
	long long int	b;
	long long int	*set;

	a = 0;
	set = malloc((argc - 1) * sizeof(long long int));
	while (a < argc - 1)
	{
		set[a] = ft_atoi(argv[a + 1]);
		if (set[a] > INT_MAX || set[a] < INT_MIN)
			return (ft_free_and_false(set));
		b = 0;
		while (b < a)
		{
			if (set[b] == set[a])
				return (ft_free_and_false(set));
			b++;
		}
		a++;
	}
	free(set);
	return (true);
}

static bool	ft_labels_are_sorted(int argc, char *argv[])
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

bool	ft_validate_args(int argc, char *argv[])
{
	if (argc < 3)
		return (false);
	else if (!ft_labels_are_integer_only(argc, argv))
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (false);
	}	
	else if (!ft_labels_are_distinct_and_size_int(argc, argv))
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (false);
	}
	else if (ft_labels_are_sorted(argc, argv))
		return (false);
	return (true);
}
