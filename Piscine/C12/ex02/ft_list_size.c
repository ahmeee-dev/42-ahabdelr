#include "../ft_list.h"
#include <unistd.h>

int ft_list_size(t_list *begin_list)
{
    int     i;

    i = 0;
    t_list *node = begin_list;
    while (node != NULL)
    {
        i++;
        node = node->next;
    }
    return (i);
}