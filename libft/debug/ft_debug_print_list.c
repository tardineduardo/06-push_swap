/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_print_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:33:53 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/26 13:56:39 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft.h"

static void	ft_print_string(t_list *trav, size_t offset)
{
	while (trav != NULL)
	{
        ft_printf("[ %s ] -> ", *(char **)((char *)trav->content + offset));
        trav = trav->next;
    }
    ft_printf("NULL\n");
}

static void	ft_print_char(t_list *trav, size_t offset)
{
	while (trav != NULL)
	{
        ft_printf("[ %c ] -> ", *(char *)((char *)trav->content + offset));
        trav = trav->next;
    }
    ft_printf("NULL\n");
}

static void	ft_print_int(t_list *trav, size_t offset)
{
	while (trav != NULL)
	{
        ft_printf("[ %d ] -> ", *(int *)((char *)trav->content + offset));
        trav = trav->next;
    }
    ft_printf("NULL\n");
}

void ft_debug_print_list(t_list **head, char *type, size_t offset)
{
    t_list *trav;

	trav = *head;
    ft_printf("\nhead ---> ");

	if (trav == NULL)
	{
	    ft_printf("NULL\n\n");
		return ;
	}
	if (ft_strcmp(type, "int") == 0)
		ft_print_int(trav, offset);
	else if (ft_strcmp(type, "char") == 0)
		ft_print_char(trav, offset);
	else if (ft_strcmp(type, "string") == 0)
		ft_print_string(trav, offset);
	else
	    ft_printf("Unsupported data type. Use \"int\", \"char\" or \"string\".\n");
}






