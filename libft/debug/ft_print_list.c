
#include "../libft.h"

static void	ft_print_string(t_list *trav, size_t offset)
{
	while (trav != NULL)
	{
        printf("[ %s ] -> ", *(char **)((char *)trav->content + offset));
        trav = trav->next;
    }
    ft_putstr_fd("NULL\n", STDOUT_FILENO);
}

static void	ft_print_char(t_list *trav, size_t offset)
{
	while (trav != NULL)
	{
        printf("[ %c ] -> ", *(char *)((char *)trav->content + offset));
        trav = trav->next;
    }
    ft_putstr_fd("NULL\n", STDOUT_FILENO);
}

static void	ft_print_int(t_list *trav, size_t offset)
{
	while (trav != NULL)
	{
        printf("[ %d ] -> ", *(int *)((char *)trav->content + offset));
        trav = trav->next;
    }
    ft_putstr_fd("NULL\n", STDOUT_FILENO);
}

void ft_print_list(t_list **head, char *type, size_t offset)
{
    t_list *trav;

	trav = *head;
    ft_putstr_fd("\nhead -> ", STDOUT_FILENO);

	if (trav == NULL)
	{
	    ft_putstr_fd("NULL\n\n", STDOUT_FILENO);
		return ;
	}

	if (ft_strcmp(type, "int") == 0)
		ft_print_int(trav, offset);
	else if (ft_strcmp(type, "char") == 0)
		ft_print_char(trav, offset);
	else if (ft_strcmp(type, "string") == 0)
		ft_print_string(trav, offset);
	else
	{
	    ft_putstr_fd("Unsupported data type. ", STDOUT_FILENO);
	    ft_putstr_fd("Use \"int\", \"char\" or \"string\"\n", STDOUT_FILENO);
	}
}






