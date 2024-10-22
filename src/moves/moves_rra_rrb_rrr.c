#include "../push_swap.h"

void rra(t_dlist **taila)
{
	int size;
	
	size = ft_dclstsize(taila);
	if (size == 0 || size == 1)
		return;
	*taila = (*taila)->next;
	ft_printf("rra\n");
}

void rrb(t_dlist **tailb)
{
	int size;
	
	size = ft_dclstsize(tailb);
	if (size == 0 || size == 1)
		return;
	*tailb = (*tailb)->next;
	ft_printf("rrb\n");
}

void rrr(t_dlist **taila, t_dlist **tailb)
{
	int		size;
	bool	a;
	bool	b;

	size = ft_dclstsize(taila);
	if (size == 0 || size == 1)
		a = false;
	else
	{
		*taila = (*taila)->next;
		a = true;
	}
	
	size = ft_dclstsize(tailb);
	if (size == 0 || size == 1)
		b = false;
	else
	{
		*tailb = (*tailb)->next;
		b = true;
	}
	if (a && b)
		ft_printf("rrr\n");
	else if (a && !b)
		ft_printf("rra\n");
	else if (!a && b)
		ft_printf("rrb\n");
}
