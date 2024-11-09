#include "push_swap.h"

void	reset_costs(t_dll *node)
{
	node->cost = 998;
	node->cost_rot = 998;
	node->cost_rev = 998;
	node->cost_opo_srot_drev = 998;
	node->cost_opo_srev_drot = 998;
	node->move_rot = false;
	node->move_rev = false;
	node->move_opo_srev_drot = false;
	node->move_opo_srot_drev = false;
}
