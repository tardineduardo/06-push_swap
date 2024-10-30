#include "../libft.h"

int	lowest(int a, int b)
{
	if (a < b)
		return (a);
	if (a > b)
		return (b);
	return (a);
}