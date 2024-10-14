/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:45:49 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/10 14:50:59 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_perror_extra(char *extra_argument, char *normal_perror)
{
	ft_putstr_fd(extra_argument, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(normal_perror);
}
