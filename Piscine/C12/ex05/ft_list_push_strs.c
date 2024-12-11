#include "ft_list.h"
#include <unistd.h>
#include <stdlib.h>

t_list *ft_list_push_strs(int size,char **strs)
{
    int     i;
    t_list  *elem;
    t_list  *n;
    
    n = NULL;
    i = 0;
    while (i < size)
    {
        if (i == 0)
        {
            elem = (t_list *)malloc(sizeof(t_list));
            elem->data = strs[i];
            elem->next = NULL;
            n = elem;
        }
        else
        {
            elem = (t_list *)malloc(sizeof(t_list));
            elem->data = strs[i];
            elem->next = n;
            n = elem;
        }
        i++;
    }
    return (n);
}