#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_info	*s;

	s = malloc(sizeof(t_info));

	//ft_validate_args(argc, argv);	

	ft_init_stacks(s, argc, argv);

	ft_play(s);

	free(s);
}