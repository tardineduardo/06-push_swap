#include "../push_swap.h"

void	split_by_order(t_info *s)
{
	t_dll *trav;
	t_dll *temp;
	int a;

	a = 0;
	trav = s->a->next;
	while (a < s->t_len / 2)
	{
		if (trav->value < s->t_len / 2)
		{
			trav = trav->next;
			pb(s, 1);
			continue ;
		}
		trav = trav->next;
		ra(s, 1);
	a++;	
	}
}
