#include "../../libft.h"

static bool ft_check_int_normal(t_dll **tail, int offset, int llen)
{
	int 	curr;
	int		next;
	t_dll *trav;

	trav = ft_dclst_find_lowest_int(tail, offset);
	while(llen > 1)
	{
		curr = *(int *)((char *)trav + offset);
		next = *(int *)((char *)trav->next + offset);
		if (curr != next - 1)
			return (false);
		trav = trav->next;
		llen--;
	}
	return (true);
}

static bool ft_check_int_reverse(t_dll **tail, int offset, int llen)
{
	int 	curr;
	int		next;
	t_dll *trav;

	trav = ft_dclst_find_highest_int(tail, offset);
	while(llen > 1)
	{
		curr = *(int *)((char *)trav + offset);
		next = *(int *)((char *)trav->next + offset);
		if (curr != next + 1)
			return (false);
		trav = trav->next;
		llen--;
	}
	return (true);
}
/* type i-int | modes n-normal, r-reverse | offssetof(struct, variable)*/
bool ft_dclst_clock_sortd_len(t_dll **tail, char mode, int offset, int llen)
{
	if (mode == 'n')
		return (ft_check_int_normal(tail, offset, llen));
	else if (mode == 'r')
		return (ft_check_int_reverse(tail, offset, llen));
	else
		ft_perror_exit("is_stack_sorted: invalid mode", 1); /// IMPROVE ERROR
	return (false);
}
