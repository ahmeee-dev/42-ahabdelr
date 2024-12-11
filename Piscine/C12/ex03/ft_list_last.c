#include "../ft_list.h"
#include <unistd.h>

t_list *ft_list_last(t_list *begin_list)
{
    t_list *node;
    
    node = begin_list;
    while (node->next != NULL)
    {
        node = node->next;
    }
    return (node);
}