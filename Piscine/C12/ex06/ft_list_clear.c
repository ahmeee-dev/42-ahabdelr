#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

void    ft_list_clear(t_list *begin_list, void(*free_fct)(void *))
{
    t_list  *n;
    t_list  *current;

    n = begin_list;
    current = begin_list;
    while (n != NULL)
    {
        current = n;
        n = current->next;
        free_fct(current->data);
        free(current);
    }
}