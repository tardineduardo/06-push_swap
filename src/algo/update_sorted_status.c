#include "../push_swap.h"
void	update_sorted_status(t_info *s)
{
	s->a_csort = false;
	s->b_csort = false;
	int diff;

	diff = abs(s->a_len - s->b_len);

	if (diff < 3 && ft_dclst_clock_sortd(&(s->a), 'n', offsetof(t_dll, value)))
		s->a_csort = true;
	if (diff < 3 && ft_dclst_clock_sortd(&(s->b), 'r', offsetof(t_dll, value)))
		s->b_csort = true;
}


void	mid_sorted_status(t_info *s)
{
	s->a_midsort = false;
	s->b_midsort= false;

	if (ft_dclst_circ_sortd(&(s->a), 'i', 'n', offsetof(t_dll, value)))
		s->a_midsort = true;
	if (ft_dclst_circ_sortd(&(s->b), 'i', 'r', offsetof(t_dll, value)))
		s->b_midsort = true;
}