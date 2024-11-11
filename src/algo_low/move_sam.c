#include "../push_swap.h"


static void	move_sam_b(t_info *s, t_dll *lowest)
{
	int	dist_nd_head;
	int dist_pr_head;
	int new_dist_pr_head;

	dist_nd_head = ft_dclst_dist_head_bidi(&(s->b), lowest);
	dist_pr_head = ft_dclst_dist_head_bidi(&(s->b), lowest->precedent);
	new_dist_pr_head = dist_pr_head - dist_nd_head;
	
	if (s->b && dist_nd_head > 0)
		while (lowest != s->b->next)
			rb(s, 1);
	else if (s->b && dist_nd_head < 0)
		while (lowest != s->b->next)
			rrb(s, 1);
	pa(s, 1);

	/// ESSA PARTE PODE ETSAR COM BUGS
	// if (new_dist_pr_head > 0)
	// 	while (lowest->precedent != s->b->next)
	// 		rb(s, 1);
	// else if (new_dist_pr_head < 0)
	// 	while (lowest->precedent != s->b->next)
	// 		rrb(s, 1);
	//pb(s, 1);
	return ;
}

static void	move_sam_a(t_info *s, t_dll *lowest)
{
	int	dist_nd_head;
	int dist_pr_head;
	int new_dist_pr_head;

	dist_nd_head = ft_dclst_dist_head_bidi(&(s->a), lowest);
	dist_pr_head = ft_dclst_dist_head_bidi(&(s->a), lowest->precedent->next);
	new_dist_pr_head = dist_pr_head - dist_nd_head;
	
	if (s->a && dist_nd_head > 0)
		while (lowest != s->a->next)
			ra(s, 1);
	else if (s->a && dist_nd_head < 0)
		while (lowest != s->a->next)
			rra(s, 1);
	pb(s, 1);
	// if (new_dist_pr_head > 0)
	// 	while (lowest->precedent != s->a)
	// 		ra(s, 1);
	// else if (new_dist_pr_head < 0)
	// 	while (lowest->precedent != s->a)
	// 		rra(s, 1);
	//pa(s, 1);
	return ;
}

static void move_sam(t_info *s, t_dll *lowest)
{
	if (s->dst_name == 'b')
		move_sam_a(s, lowest);
	else if (s->dst_name == 'a')
		move_sam_b(s, lowest);
	return ;
}