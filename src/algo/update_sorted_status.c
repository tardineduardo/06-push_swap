#include "../push_swap.h"

void	update_sorted_status(t_table *s)
{
	s->a_is_clock_sorted = false;
	s->b_is_clock_sorted = false;
	int diff;

	diff = abs(s->a_len - s->b_len);

	if (diff < s->t_len/10 && ft_dclst_clock_sortd(&(s->a), 'n', offsetof(t_dll, value)))
		s->a_is_clock_sorted = true;
	if (diff < s->t_len/10 && ft_dclst_clock_sortd(&(s->b), 'r', offsetof(t_dll, value)))
		s->b_is_clock_sorted = true;
}
