/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dclist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:33:57 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 16:11:44 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_print_arrow(t_dlist **tail, int countlen, int fd);
static int	ft_print_int(t_dlist **tail, t_dlist *trav, size_t offset, int fd);
static int	ft_print_char(t_dlist **tail, t_dlist *trav, size_t offset, int fd);
static int	ft_print_string(t_dlist **tail, t_dlist *trav, size_t offset, int fd);

void ft_print_dclist(t_dlist **tail, char *type, size_t offset, int fd)
{
	int countlen;
	t_dlist *trav;

	if (ft_dclstsize(tail) == -1)
		return;

	countlen = 0;
	trav = *tail;
	if (trav == NULL)
	{
	    ft_dprintf(fd, "\nNULL <---- tail\n\n");
		return ;
	}
	if (ft_strcmp(type, "int") == 0)
		countlen += ft_print_int(tail, trav, offset, fd);
	else if (ft_strcmp(type, "char") == 0)
		countlen += ft_print_char(tail, trav, offset, fd);
	else if (ft_strcmp(type, "string") == 0)
		countlen += ft_print_string(tail, trav, offset, fd);
	else
	    ft_dprintf(fd, "Unsupported data type. Use \"int\", \"char\" or \"string\".\n");
	ft_print_arrow(tail, countlen, fd);
}

static int	ft_print_string(t_dlist **tail, t_dlist *trav, size_t offset, int fd)
{
	int countlen;

	countlen = 0;
	trav = trav->next;
	while (trav != *tail)
	{
        countlen += ft_dprintf(fd, "[ %s ] <--> ", *(char **)((char *)trav->content + offset));
        trav = trav->next;
	}
	countlen += ft_dprintf(fd, "[ %s ]", *(char **)((char *)trav->content + offset));
    ft_dprintf(fd, " <---- tail");
	return (countlen);
}

static int	ft_print_char(t_dlist **tail, t_dlist *trav, size_t offset, int fd)
{
	int countlen;

	countlen = 0;
	trav = trav->next;
	while (trav != *tail)
	{
        countlen += ft_dprintf(fd, "[ %c ] <--> ", *(char *)((char *)trav->content + offset));
        trav = trav->next;
	}
	countlen += ft_dprintf(fd, "[ %c ]", *(char *)((char *)trav->content + offset));
    ft_dprintf(fd, " <---- tail");
	return (countlen);
}

int	ft_print_int(t_dlist **tail, t_dlist *trav, size_t offset, int fd)
{
	int countlen;

	countlen = 0;
	trav = trav->next;
	ft_dprintf(fd, "\n");
	while (trav != *tail)
	{
        countlen += ft_dprintf(fd, "[ %d ] <--> ", *(int *)((char *)trav->content + offset));
        trav = trav->next;
	}
	countlen += ft_dprintf(fd, "[ %d ]", *(int *)((char *)trav->content + offset));
    ft_dprintf(fd, " <---- tail");
	return (countlen);
}

void ft_print_arrow(t_dlist **tail, int countlen, int fd)
{
	int a;
	
	a = ft_dclstsize(tail);

	if(a == 1)
	{
		ft_dprintf(fd, "\n|   |\n");
		ft_dprintf(fd, "+>-<+\n\n");
		return ;
	}		
	ft_dprintf(fd, "\n  |");
	a = 0;
	while (a < countlen - 6)
	{
		ft_dprintf(fd, " ");
		a++;
	}
	ft_dprintf(fd, "|\n");
	ft_dprintf(fd, "  +-<");
	a = 0;
	while (a < countlen - 10)
	{
		ft_dprintf(fd, "-");
		a++;
	}
	ft_dprintf(fd, ">-+\n");
	ft_dprintf(fd, "\n");
}
