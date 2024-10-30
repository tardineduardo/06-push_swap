#include "../push_swap.h"

void	update_sorted_status(t_info *s)
{
	if (ft_dclst_circ_sortd(&(s->a), 'i', 'i', offsetof(t_dll, value)))
		s->a_is_csortd = true;
	if (ft_dclst_circ_sortd(&(s->b), 'i', 'o', offsetof(t_dll, value)))
		s->b_is_csortd = true;

}

