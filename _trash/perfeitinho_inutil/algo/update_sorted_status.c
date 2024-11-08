#include "../push_swap.h"

void	update_sorted_status(t_info *s)
{
	bool a_is_longer;
	bool b_is_longer;

	s->a_is_clock_sorted = false;
	s->b_is_clock_sorted = false;
	a_is_longer = false;
	b_is_longer = false;

	if (s->a_len > s->b_len)
		a_is_longer = true;
	else if (s->a_len < s->b_len)
		b_is_longer = true;	
	else
	{
		a_is_longer = true;
		b_is_longer = true;
	}	
	if (a_is_longer && ft_dclst_clock_sortd(&(s->a), 'n', offsetof(t_dll, value)))
		s->a_is_clock_sorted = true;
	if (b_is_longer && ft_dclst_clock_sortd(&(s->b), 'r', offsetof(t_dll, value)))
		s->b_is_clock_sorted = true;
}