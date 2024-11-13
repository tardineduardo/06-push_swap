#include "checker.h"

static void ft_run_cmd(char *cmd, t_table *s)
{
	if(ft_strcmp(cmd, "pa\n") == 0)
		ft_pa(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "pb\n") == 0)
		ft_pb(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "sa\n") == 0)
		ft_sa(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "sb\n") == 0)
		ft_sb(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "ss\n") == 0)
		ft_ss(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "ra\n") == 0)
		ft_ra(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "rb\n") == 0)
		ft_rb(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "rr\n") == 0)
		ft_rr(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "rra\n") == 0)
		ft_rra(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "rrb\n") == 0)
		ft_rrb(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "rrr\n") == 0)
		ft_rrr(s, STDOUT_FILENO);
	return ;
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*cmd;
	t_table	*s;

	s = malloc(sizeof(t_table));
	ft_checker_validate(argc, argv);
	ft_checker_init(s, argc, argv);
	fd = STDIN_FILENO;
	while (1)
	{
		cmd = get_next_line(fd);
		if (!cmd)
			break ;
		ft_printf("line read: %s", cmd);
		ft_run_cmd(cmd, s);
		free(cmd);
	}
	if(ft_dclst_circ_sortd(&(s->a), 'i', offsetof(t_dll, label)))
		ft_printf("OK\n");
	else
		ft_printf("K0\n");
	return (0);
}