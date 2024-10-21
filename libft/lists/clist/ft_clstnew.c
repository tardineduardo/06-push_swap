#include "../../libft.h"

t_list	*ft_clstnew(void *content)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	temp->content = content;
	temp->next = temp;
	return (temp);
}
