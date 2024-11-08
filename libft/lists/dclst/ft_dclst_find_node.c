#include "../../libft.h"

t_dll	*ft_dclst_find_node(t_dll **tail, t_dll *node, int len)
{
	t_dll	*trav;
	int		i;

	if (!tail || !(*tail) || !node)
		return (NULL);
	trav = *tail;
	
	i = 0;
	while (i < len)
	{
		if (trav == node)
			return (trav);
		trav = trav->next;
		i++;
	}
	return (NULL);
}
