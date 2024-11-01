#include "../push_swap.h"

void	update_sorted_status(t_info *s)
{
	if (ft_dclst_clock_sortd_len(&(s->a), 'n', offsetof(t_dll, value), s->a_len))
		s->a_csort = true;
	if (ft_dclst_clock_sortd_len(&(s->b), 'r', offsetof(t_dll, value), s->b_len))
		s->b_csort = true;

}

