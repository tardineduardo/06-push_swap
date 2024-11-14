/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:55:39 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/13 20:31:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_run_cmd(char *cmd, t_table *s)
{
	int	trash_fd;

	trash_fd = open("/dev/null", O_WRONLY);
	if (ft_strcmp(cmd, "pa\n") == 0)
		ft_pa(s, trash_fd);
	else if (ft_strcmp(cmd, "pb\n") == 0)
		ft_pb(s, trash_fd);
	else if (ft_strcmp(cmd, "sa\n") == 0)
		ft_sa(s, trash_fd);
	else if (ft_strcmp(cmd, "sb\n") == 0)
		ft_sb(s, trash_fd);
	else if (ft_strcmp(cmd, "ss\n") == 0)
		ft_ss(s, trash_fd);
	else if (ft_strcmp(cmd, "ra\n") == 0)
		ft_ra(s, trash_fd);
	else if (ft_strcmp(cmd, "rb\n") == 0)
		ft_rb(s, trash_fd);
	else if (ft_strcmp(cmd, "rr\n") == 0)
		ft_rr(s, trash_fd);
	else if (ft_strcmp(cmd, "rra\n") == 0)
		ft_rra(s, trash_fd);
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		ft_rrb(s, trash_fd);
	else if (ft_strcmp(cmd, "rrr\n") == 0)
		ft_rrr(s, trash_fd);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*cmd;
	t_table	*s;

	s = malloc(sizeof(t_table));
	ft_checker_validate(argc, argv, s);
	ft_checker_init(s, argc, argv);
	ft_debug_print_dclist(&(s->a), "int", offsetof(t_dll, label), 1);
	fd = STDIN_FILENO;
	while (1)
	{
		cmd = get_next_line(fd);
		if (!cmd)
			break ;
		ft_run_cmd(cmd, s);
		free(cmd);
	}
	ft_debug_print_dclist(&(s->a), "int", offsetof(t_dll, label), 1);
	if (ft_dclst_list_sortd(&(s->a), offsetof(t_dll, label)))
		ft_printf("OK\n");
	else
		ft_printf("K0\n");
	close (fd);	
	return (0);
}
