#include <unistd.h>
#include <stdlib.h>
#include "../ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
    t_list  *n;
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));
    node->data = data;
    if (*begin_list == NULL)
    {
        *begin_list = node;
    }
    else 
    {
        n = *begin_list;
        while (n->next != NULL)
        {
            n = n->next;
        }
        n->next = node;
    }
}
