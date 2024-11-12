#include "../push_swap.h"

void	update_sorted_status(t_table *s)
{
	bool a_is_long_enough;
	bool b_is_long_enough;

	s->a_is_clock_sorted = false;
	s->b_is_clock_sorted = false;
	a_is_long_enough = false;
	b_is_long_enough = false;

	if (s->a_len >= s->b_len)
		a_is_long_enough = true;
	if (s->a_len <= s->b_len)
		b_is_long_enough = true;
	
	if (a_is_long_enough && ft_dclst_clock_sortd(&(s->a), 'n', offsetof(t_dll, value)))
		s->a_is_clock_sorted = true;
	if (b_is_long_enough && ft_dclst_clock_sortd(&(s->b), 'r', offsetof(t_dll, value)))
		s->b_is_clock_sorted = true;
}