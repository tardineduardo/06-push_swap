#include "../push_swap.h"

void	split_by_order(t_info *s)
{
	t_dll *trav;
	trav = s->a->next;
	
	while (s->b_len < 3)
	{
		if (s->a->next->value > s->t_len / 2)
		{
			pb(s, 1);
			continue;
		}
		ra(s, 1);	
	}
}



void	split_by_alternate_order(t_info *s)
{
	bool low;
	bool high;
	t_dll *trav;
	t_dll *temp;

	low = true;
	high = true;	
	trav = s->a->next;
	while (s->a_len - s->b_len >= 2)
	{
		if (low)
		{
			if (trav->value < s->t_len / 2)
			{
				trav = trav->next;
				low = false;
				high = true;
				pb(s, 1);
				continue ;
			}
			trav = trav->next;
			ra(s, 1);	
		}
		else if (high)
		{
			if (trav->value > s->t_len / 2)
			{
				trav = trav->next;
				low = true;
				high = false;
				pb(s, 1);
				continue ;
			}
			trav = trav->next;
			ra(s, 1);
		}
	//ft_play_print_values(&(s->a), &(s->b));
	}
}