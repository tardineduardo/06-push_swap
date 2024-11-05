#include "../push_swap.h"

void	update_sorted_status(t_info *s)
{
	bool a_is_long_enough;
	bool b_is_long_enough;

	s->a_csort = false;
	s->b_csort = false;
	a_is_long_enough = false;
	b_is_long_enough = false;

	if (s->a_len >= s->b_len)
		a_is_long_enough = true;
	if (s->a_len <= s->b_len)
		b_is_long_enough = true;
	
	if (a_is_long_enough && ft_dclst_clock_sortd(&(s->a), 'n', offsetof(t_dll, value)))
		s->a_csort = true;
	if (b_is_long_enough && ft_dclst_clock_sortd(&(s->b), 'r', offsetof(t_dll, value)))
		s->b_csort = true;
}

void	update_split1(t_info *s)
{
	int sortedcount_a = 0;
	int sortedcount_b = 0;
	s->debug_hi_sa = 0;
	s->debug_hi_sb = 0;

	t_dll *trav;
	int		i;
	if (s->a)
	{
		i = 0;
		trav = s->a;
		while (i < s->a_len)
		{
			if (trav->value + 1 == trav->next->value)
			{
				sortedcount_a++;
				if (sortedcount_a > s->debug_hi_sa)
					s->debug_hi_sa = sortedcount_a;
			}
			else
				sortedcount_a = 0;
			trav = trav->next;
			i++;
		}
	}
	if (s->b)
	{
		i = 0;
		trav = s->b;
		while (i < s->b_len)
		{
			if (trav->value - 1 == trav->next->value)
			{
				sortedcount_b++;
				if (sortedcount_b > s->debug_hi_sb)
					s->debug_hi_sb = sortedcount_b;
			}
			else
				sortedcount_b = 0;
			trav = trav->next;
			i++;
		}
	}
}
