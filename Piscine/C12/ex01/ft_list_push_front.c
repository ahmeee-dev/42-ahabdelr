#include "../ft_list.h"
#include <unistd.h>
#include <stdlib.h>

void    ft_list_push_front(t_list **begin_list, void *data)
{
    t_list  *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data = data;
    new_node->next = *begin_list;
    *begin_list = new_node;
}