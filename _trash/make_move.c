#include "../push_swap.h"


static void	move_swp_a(t_table *s, t_dll *lowest)
{
	int	dist_nd_head;

	dist_nd_head = ft_dclst_dist_head_bidi(&(s->a), lowest);
	if (dist_nd_head > 0)
		while (lowest != s->a->next)
			rra(s, 1);
	if (dist_nd_head < 0)
		while (lowest->pre != s->a)
			ra(s, 1);
	sa(s, 1);
	s->block_swap = true;
	return ;
}

static void	move_swp_b(t_table *s, t_dll *lowest)
{
	int	dist_nd_head;

	dist_nd_head = ft_dclst_dist_head_bidi(&(s->b), lowest);
	if (dist_nd_head > 0)
		while (lowest != s->b->next)
			rrb(s, 1);
	if (dist_nd_head < 0)
		while (lowest->pre != s->b)
			rb(s, 1);
	sb(s, 1);
	s->block_swap = true;
	return ;	
}

static void move_swp(t_table *s, t_dll *lowest)
{
	if (s->dst_name == 'b')
		move_swp_a(s, lowest);
	else if (s->dst_name == 'a')
		move_swp_b(s, lowest);
	return ;
}

static void	move_sam_b(t_table *s, t_dll *lowest)
{
	int	dist_nd_head;
	int dist_pr_head;
	int new_dist_pr_head;

	dist_nd_head = ft_dclst_dist_head_bidi(&(s->b), lowest);
	dist_pr_head = ft_dclst_dist_head_bidi(&(s->b), lowest->pre);
	new_dist_pr_head = dist_pr_head - dist_nd_head;
	
	if (s->b && dist_nd_head > 0)
		while (lowest != s->b->next)
			rrb(s, 1);
	else if (s->b && dist_nd_head < 0)
		while (lowest != s->b->next)
			rb(s, 1);
	pa(s, 1);

	/// ESSA PARTE PODE ETSAR COM BUGS
	// if (new_dist_pr_head > 0)
	// 	while (lowest->pre != s->b->next)
	// 		rb(s, 1);
	// else if (new_dist_pr_head < 0)
	// 	while (lowest->pre != s->b->next)
	// 		rrb(s, 1);
	//pb(s, 1);
	return ;
}

static void	move_sam_a(t_table *s, t_dll *lowest)
{
	int	dist_nd_head;
	int dist_pr_head;
	int new_dist_pr_head;

	dist_nd_head = ft_dclst_dist_head_bidi(&(s->a), lowest);
	dist_pr_head = ft_dclst_dist_head_bidi(&(s->a), lowest->pre->next);
	new_dist_pr_head = dist_pr_head - dist_nd_head;
	
	if (s->a && dist_nd_head > 0)
		while (lowest != s->a->next)
			rra(s, 1);
	else if (s->a && dist_nd_head < 0)
		while (lowest != s->a->next)
			ra(s, 1);
	pb(s, 1);
	// if (new_dist_pr_head > 0)
	// 	while (lowest->pre != s->a)
	// 		ra(s, 1);
	// else if (new_dist_pr_head < 0)
	// 	while (lowest->pre != s->a)
	// 		rra(s, 1);
	//pa(s, 1);
	return ;
}

static void move_sam(t_table *s, t_dll *lowest)
{
	if (s->dst_name == 'b')
		move_sam_a(s, lowest);
	else if (s->dst_name == 'a')
		move_sam_b(s, lowest);
	return ;
}

static void move_opo(t_table *s, t_dll *lowest)
{
	if (s->dst_name == 'a')
	{
		if (lowest->opo_way_a == 'f')
		{
			while (lowest != s->b->next)
				rb(s, 1);
			while (lowest->pre != s->a)
				rra(s, 1);
			pa(s, 1);
		}
		else if (lowest->opo_way_a == 'r')
		{
			while (lowest != s->b->next)
				rrb(s, 1);
			while (lowest->pre != s->a)
				ra(s, 1);
			pa(s, 1);
		}
	}

	//////////////////////////// O B ESTA CHECADO< MAS PODE TER ERRO NO A!!!!

	if (s->dst_name == 'b')
	{
		if (lowest->opo_way_a == 'f')
		{
			while (lowest != s->a->next)
				rra(s, 1);
			while (lowest->pre != s->b->next)
				rb(s, 1);
			pb(s, 1);
		}
		else if (lowest->opo_way_a == 'r')
		{
			while (lowest != s->a->next)
				ra(s, 1);
			while (lowest->pre != s->b->next)
				rrb(s, 1);
			pb(s, 1);
		}	
	}
}

static void move_rev(t_table *s, t_dll *lowest)
{
	if (s->a && s->dst_name == 'a')
	{
		while (lowest != s->b->next && lowest->pre != s->a)
			rr(s, 1);
		while (lowest != s->b->next)
			rb(s, 1);
		while (lowest->pre != s->a)
			ra(s, 1);
		pa(s, 1);
	}
	if (s->b && s->dst_name == 'b')
	{
		while (lowest != s->a->next && lowest->pre != s->b->next)
			rr(s, 1);
		while (lowest != s->a->next)
			ra(s, 1);
		while (lowest->pre != s->b->next)
			rb(s, 1);
		pb(s, 1);
	}
}

static void move_rot(t_table *s, t_dll *lowest)
{
	if (s->dst_name == 'a')
	{
		while (lowest != s->b->next && lowest->pre != s->a)
			rrr(s, 1);
		while (lowest != s->b->next)
			rrb(s, 1);
		while (lowest->pre != s->a)
			rra(s, 1);
		pa(s, 1);	
	}
	if (s->dst_name == 'b')
	{
		while (lowest != s->a->next && lowest->pre != s->b->next)
			rrr(s, 1);
		while (lowest != s->a->next)
			rra(s, 1);
		while (lowest->pre != s->b->next)
			rrb(s, 1);
		pb(s, 1);
	}

}

void	pick_move(t_table *s, t_dll *lowest)
{
	int file;


	
	if (lowest->move_swp && !(s->block_swap))
	{
		file = open("analysis.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
		ft_dprintf(file, "move_swp\t%i\n", lowest->cost);
		move_swp(s, lowest);
	}
	else
	{
		if (lowest->move_rot)
		{
			file = open("analysis.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
			ft_dprintf(file, "move_rot\t%i\n", lowest->cost);
			move_rot(s, lowest);
		}
		else if (lowest->move_rev)
		{
			file = open("analysis.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
			ft_dprintf(file, "move_rev\t%i\n", lowest->cost);
			move_rev(s, lowest);
		}
		else if (lowest->move_sam)
		{
			file = open("analysis.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
			ft_dprintf(file, "move_sam\t%i\n", lowest->cost);
			move_sam(s, lowest);
		}
		else if (lowest->move_opo)
		{
			file = open("analysis.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
			ft_dprintf(file, "move_opo\t%i\n", lowest->cost);
			move_opo(s, lowest);
		}
		s->block_swap = false;
	}
	return ;
}

void	make_move(t_table *s)
{
	t_dll	*lowst;
	t_dll	*lowst_a;
	t_dll	*lowst_b;


	lowst_a = find_lowest_cost(&(s->a));
	lowst_b = find_lowest_cost(&(s->b));
	if (lowst_a && lowst_b && lowst_a->cost == lowst_b->cost)
	{
		if (s->a_len > s->b_len)
		{
			s->dst_name = 'b';
			lowst = lowst_a;
			s->last_moved = lowst;
		}
		if (s->a_len <= s->b_len)
		{
			s->dst_name = 'a';
			lowst = lowst_b;
			s->last_moved = lowst;
		}
	}
	else if (lowst_a && lowst_b)
	{
		if (lowst_a->cost < lowst_b->cost)
		{
			s->dst_name = 'b';
			lowst = lowst_a;
			s->last_moved = lowst;
		}
		else
		{	
			s->dst_name = 'a';
			lowst = lowst_b;
			s->last_moved = lowst;
		}
	}
	else if (lowst_a && !lowst_b)
	{
			s->dst_name = 'b';
			lowst = lowst_a;
			s->last_moved = lowst;
	}
	else if (!lowst_a && lowst_b)
	{	
			s->dst_name = 'a';
			lowst = lowst_b;
			s->last_moved = lowst;
	}
	pick_move(s, lowst);
}
