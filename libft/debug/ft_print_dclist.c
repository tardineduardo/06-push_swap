
#include "../libft.h"

static void	ft_print_arrow(t_dlist **tail, int countlen);
static int	ft_print_int(t_dlist **tail, t_dlist *trav, size_t offset);
static int	ft_print_char(t_dlist **tail, t_dlist *trav, size_t offset);
static int	ft_print_string(t_dlist **tail, t_dlist *trav, size_t offset);

void ft_print_dclist(t_dlist **tail, char *type, size_t offset)
{
	int countlen;
	t_dlist *trav;

	countlen = 0;
	trav = *tail;
	if (trav == NULL)
	{
	    ft_printf("NULL\n\n");
		return ;
	}
	if (ft_strcmp(type, "int") == 0)
		countlen += ft_print_int(tail, trav, offset);
	else if (ft_strcmp(type, "char") == 0)
		countlen += ft_print_char(tail, trav, offset);
	else if (ft_strcmp(type, "string") == 0)
		countlen += ft_print_string(tail, trav, offset);
	else
	    ft_printf("Unsupported data type. Use \"int\", \"char\" or \"string\".\n");
	ft_print_arrow(tail, countlen);
}

static int	ft_print_string(t_dlist **tail, t_dlist *trav, size_t offset)
{
	int countlen;

	countlen = 0;
	trav = trav->next;
	while (trav != *tail)
	{
        countlen += ft_printf("[ %s ] <--> ", *(char *)((char *)trav->content + offset));
        trav = trav->next;
	}
	countlen += ft_printf("[ %s ]", *(char *)((char *)trav->content + offset));
    ft_printf("<---- tail\n");
	return (countlen);
}

static int	ft_print_char(t_dlist **tail, t_dlist *trav, size_t offset)
{
	int countlen;

	countlen = 0;
	trav = trav->next;
	while (trav != *tail)
	{
        countlen += ft_printf("[ %c ] <--> ", *(char *)((char *)trav->content + offset));
        trav = trav->next;
	}
	countlen += ft_printf("[ %c ]", *(char *)((char *)trav->content + offset));
    ft_printf("<---- tail\n");
	return (countlen);
}

int	ft_print_int(t_dlist **tail, t_dlist *trav, size_t offset)
{
	int countlen;

	countlen = 0;
	trav = trav->next;
	ft_printf("\n");
	while (trav != *tail)
	{
        countlen += ft_printf("[ %d ] <--> ", *(int *)((char *)trav->content + offset));
        trav = trav->next;
	}
	countlen += ft_printf("[ %d ]", *(int *)((char *)trav->content + offset));
    ft_printf(" <---- tail");
	return (countlen);
}


void ft_print_arrow(t_dlist **tail, int countlen)
{
	int a;
	
	a = ft_dclstsize(tail);

	if(a == 1)
	{
		ft_printf("\n|   |\n");
		ft_printf("+>-<+\n");
		return ;
	}		
	ft_printf("\n  |");
	a = 0;
	while (a < countlen - 6)
	{
		ft_printf(" ");
		a++;
	}
	ft_printf("|\n");
	ft_printf("  +-<");
	a = 0;
	while (a < countlen - 10)
	{
		ft_printf("-");
		a++;
	}
	ft_printf(">-+\n");
	ft_printf("\n");
}





