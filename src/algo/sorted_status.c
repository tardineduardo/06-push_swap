#include "../push_swap.h"

void	update_sorted_status(t_table *s)
{
	s->a_is_clock_sorted = false;
	s->b_is_clock_sorted = false;
	if (ft_dclst_clock_sortd(&(s->a), 'n', offsetof(t_dll, value)))
		s->a_is_clock_sorted = true;
	if (ft_dclst_clock_sortd(&(s->b), 'r', offsetof(t_dll, value)))
		s->b_is_clock_sorted = true;
	return ;
}

void	update_partially_sorted_status(t_table *s)
{
	s->a_partially_sorted = false;
	s->b_partially_sorted = false;
	if (ft_dclst_circ_sortd(&(s->a), 'i', 'n', offsetof(t_dll, value)))
		s->a_partially_sorted = true;
	if (ft_dclst_circ_sortd(&(s->b), 'i', 'r', offsetof(t_dll, value)))
		s->b_partially_sorted = true;
	return ;
}
