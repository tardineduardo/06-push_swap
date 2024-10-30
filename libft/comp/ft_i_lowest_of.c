#include "../libft.h"

int	ft_i_lowest_of(int a, int b)
{
	if (a < b)
		return (a);
	if (a > b)
		return (b);
	return (a);
}