#include "../push_swap.h"

void ra(t_dlist **taila)
{
	int size;
	
	size = ft_dclstsize(taila);
	if (size == 0 || size == 1)
		return;
	*taila = (*taila)->prev;
	ft_printf("ra\n");
}

void rb(t_dlist **tailb)
{
	int size;
	
	size = ft_dclstsize(tailb);
	if (size == 0 || size == 1)
		return;
	*tailb = (*tailb)->prev;
	ft_printf("rb\n");
}

void rr(t_dlist **taila, t_dlist **tailb)
{
	int		size;
	bool	a;
	bool	b;

	size = ft_dclstsize(taila);
	if (size == 0 || size == 1)
		a = false;
	else
	{
		*taila = (*taila)->prev;
		a = true;
	}
	
	size = ft_dclstsize(tailb);
	if (size == 0 || size == 1)
		b = false;
	else
	{
		*tailb = (*tailb)->prev;
		b = true;
	}
	if (a && b)
		ft_printf("rr\n");
	else if (a && !b)
		ft_printf("ra\n");
	else if (!a && b)
		ft_printf("rb\n");
}
