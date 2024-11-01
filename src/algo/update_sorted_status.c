#include "../push_swap.h"

void	update_sorted_status(t_info *s)
{
	s->a_csort = false;
	s->b_csort = false;
	if (ft_dclst_circ_sortd(&(s->a), 'i', 'i', offsetof(t_dll, value)))
		s->a_csort = true;
	if (ft_dclst_circ_sortd(&(s->b), 'i', 'o', offsetof(t_dll, value)))
		s->b_csort = true;
}



