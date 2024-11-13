#include "checker.h"

static void ft_run_cmd(char *cmd, t_table *s)
{
	if(ft_strcmp(cmd, "pa") == 0)
		ft_pa(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "pb") == 0)
		ft_pb(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "sa") == 0)
		ft_sa(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "sb") == 0)
		ft_sb(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "ss") == 0)
		ft_ss(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "ra") == 0)
		ft_ra(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "rb") == 0)
		ft_rb(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "rr") == 0)
		ft_rr(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "rra") == 0)
		ft_rra(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "rrb") == 0)
		ft_rrb(s, STDOUT_FILENO);
	else if(ft_strcmp(cmd, "rrr") == 0)
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
		ft_run_cmd(cmd, s);
		free(cmd);
	}
	if(ft_dclst_list_sortd(&(s->a), "int", 'n', offsetof(t_dll, label)))
		ft_printf("OK\n");
	else
		ft_printf("K0\n");
	return (0);
}