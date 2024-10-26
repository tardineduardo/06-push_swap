/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:45 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/26 12:31:38 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_init_stack1(t_dlist **stack, int argc, char *argv[])
{
	int		a;
	t_node	*node;

	a = 1;

	char **s = calloc(6, sizeof(char *));
	s[0] = calloc(100, 1);
	s[1] = calloc(100, 1);
	s[2] = calloc(100, 1);
	s[3] = calloc(100, 1);
	s[4] = calloc(100, 1);
	s[0] = "banana";
	s[1] = "uva";
	s[2] = "pera";
	s[3] = "maca";
	s[4] = "caqui";
	s[5] = 0;

	int b = 0;
	while(a < argc)
	{
		node = malloc(sizeof(t_node));
			// protect
		node->label = ft_atoi(argv[a]);
		node->stringz = s[b];

		ft_dclstadd_back(stack, ft_dclstnew((void *)node));
		a++;
		b++;
	}
}
void ft_init_stack2(t_dlist **stack, int argc, char *argv[])
{
	int		a;
	t_node	*node;

	a = 1;

	char **s = calloc(6, sizeof(char *));
	s[0] = calloc(100, 1);
	s[1] = calloc(100, 1);
	s[2] = calloc(100, 1);
	s[3] = calloc(100, 1);
	s[4] = calloc(100, 1);
	s[0] = "banana";
	s[1] = "uva";
	s[2] = "pera";
	s[3] = "maca";
	s[4] = "caqui";
	s[5] = 0;

	int b = 0;
	while(a < 4)
	{
		node = malloc(sizeof(t_node));
			// protect
		node->label = ft_atoi(argv[a]);
		node->stringz = s[b];

		ft_dclstadd_back(stack, ft_dclstnew((void *)node));
		a++;
		b++;
	}
}
