/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:42:06 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/18 15:35:42 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_free_and_false(void *ptr)
{
	free(ptr);
	return (false);
}

bool	ft_free_and_true(void *ptr)
{
	free(ptr);
	return (true);
}

void *ft_free_and_null(void *ptr)
{
	free(ptr);
	return (NULL);
}

