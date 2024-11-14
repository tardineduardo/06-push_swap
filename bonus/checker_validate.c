/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:12:52 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/14 13:26:47 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

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

void	ft_checker_validate(int argc, char *argv[])
{
	if (argc < 3)
		exit(0);
	else if (!ft_labels_are_integer_only(argc, argv))
		ft_error_exit("Error\n", EINVAL);
	else if (!ft_labels_are_distinct_and_size_int(argc, argv))
		ft_error_exit("Error\n", EINVAL);
	else if (ft_labels_are_sorted(argc, argv))
		exit(0);
}
