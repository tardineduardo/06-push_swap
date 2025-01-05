/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:55:39 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/17 15:02:00 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_checker_error(t_checker *checker)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	checker->error_status = 1;
	return ;
}	

static void	ft_run_cmd(t_checker *checker, t_table *s)
{
	checker->trash_fd = open("/dev/null", O_WRONLY);
	if (ft_strcmp(checker->cmd, "pa\n") == 0)
		ft_pa(s, checker->trash_fd);
	else if (ft_strcmp(checker->cmd, "pb\n") == 0)
		ft_pb(s, checker->trash_fd);
	else if (ft_strcmp(checker->cmd, "sa\n") == 0)
		ft_sa(s, checker->trash_fd);
	else if (ft_strcmp(checker->cmd, "sb\n") == 0)
		ft_sb(s, checker->trash_fd);
	else if (ft_strcmp(checker->cmd, "ss\n") == 0)
		ft_ss(s, checker->trash_fd);
	else if (ft_strcmp(checker->cmd, "ra\n") == 0)
		ft_ra(s, checker->trash_fd);
	else if (ft_strcmp(checker->cmd, "rb\n") == 0)
		ft_rb(s, checker->trash_fd);
	else if (ft_strcmp(checker->cmd, "rr\n") == 0)
		ft_rr(s, checker->trash_fd);
	else if (ft_strcmp(checker->cmd, "rra\n") == 0)
		ft_rra(s, checker->trash_fd);
	else if (ft_strcmp(checker->cmd, "rrb\n") == 0)
		ft_rrb(s, checker->trash_fd);
	else if (ft_strcmp(checker->cmd, "rrr\n") == 0)
		ft_rrr(s, checker->trash_fd);
	else
		ft_checker_error(checker);
}

static void	ft_check_loop(t_checker *checker, t_table *s)
{
	while (1)
	{
		checker->error_status = 0;
		checker->cmd = get_next_line(checker->fd);
		if (!checker->cmd)
			break ;
		ft_run_cmd(checker, s);
		free(checker->cmd);
		if (checker->error_status == 1)
			break ;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	t_checker	checker;
	t_table		*s;

	ft_checker_validate(argc, argv);
	s = malloc(sizeof(t_table));
	ft_checker_init(s, argc, argv);
	checker.fd = STDIN_FILENO;
	ft_check_loop(&checker, s);
	if (ft_dclst_list_sortd(&(s->a), get_label) && checker.error_status == 0)
		ft_printf("OK\n");
	else if (checker.error_status == 0)
		ft_printf("K0\n");
	if (s->a)
		ft_dclstclear_simple(&(s->a));
	if (s->b)
		ft_dclstclear_simple(&(s->b));
	free(s);
	return (0);
}
