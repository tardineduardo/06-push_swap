/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:04:55 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/12 19:15:30 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_error_exit(char *mess, int exit_nb)
{
	ft_putstr_fd(mess, STDERR_FILENO);
	exit(exit_nb);
}
