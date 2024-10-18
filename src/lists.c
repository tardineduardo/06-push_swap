/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:15:04 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/17 20:27:01 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	a->content = content;
	a->next = NULL;
	return (a);
}

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*trav;

	trav = lst;
	counter = 0;
	while (trav != NULL)
	{
		trav = trav->next;
		counter++;
	}
	return (counter);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}


t_list	*ft_lstlast(t_list *lst)
{
	t_list	*trav;

	if (lst == NULL)
		return (NULL);
	trav = lst;
	while (trav->next != NULL)
		trav = trav->next;
	return (trav);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp1;
	t_list	*temp2;

	if (lst == NULL || *lst == NULL)
		return ;
	temp1 = *lst;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		(*del)(temp1->content);
		free(temp1);
		temp1 = temp2;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(*del)((void *)lst->content);
	free(lst);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL)
	{
		(*f)((void *)temp->content);
		temp = temp->next;
	}
}