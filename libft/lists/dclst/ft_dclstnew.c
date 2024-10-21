#include "../../libft.h"

t_dlist	*ft_dclstnew(void *content)
{
	t_dlist	*temp;

	temp = malloc(sizeof(t_dlist));
	if (!temp)
		return (NULL);
	temp->content = content;
	temp->next = temp;
	temp->prev = temp;
	return (temp);
}
