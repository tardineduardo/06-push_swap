#include "./push_swap.h"

void	set_cross_costs_to_locked(t_dll *node) /// mover para INUTILS
{
	node->cost = 999;
	node->cost_rot = 999;
	node->cost_rev = 999;
	node->cost_opo_srot_drev = 999;
	node->cost_opo_srev_drot = 999;
	node->move_rot = false;
	node->move_rev = false;
	node->move_opo_srev_drot = false;
	node->move_opo_srot_drev = false;
	return ;
}

void	reset_costs(t_dll *node) /// mover para INUTILS
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
	return ;
}

void	ft_set_cost_and_move(int dist_s_head, int dist_d_head, t_dll *node)
{
	if (dist_s_head > 0 && dist_d_head > 0)
	{
		node->move_rev = true;
		node->cost_rev = 1 + abs(dist_s_head) + abs(dist_d_head - dist_s_head);
	}
	else if (dist_s_head < 0 && dist_d_head < 0)
	{
		node->move_rot = true;
		node->cost_rot = 1 + abs(dist_s_head) + abs(dist_d_head - dist_s_head);
	}
	else if (dist_s_head <= 0 && dist_d_head >= 0)
	{
		node->move_opo_srot_drev = true;
		node->cost_opo_srot_drev = 1 + abs(dist_s_head) + abs(dist_d_head);
	}
	else if (dist_s_head >= 0 && dist_d_head <= 0)
	{
		node->move_opo_srev_drot = true;
		node->cost_opo_srev_drot = 1 + abs(dist_s_head) + abs(dist_d_head);
	}
}
