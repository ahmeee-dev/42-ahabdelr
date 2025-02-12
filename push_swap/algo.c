#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void	find_best(t_obj *obj, t_container *container)
{
	position(obj, container);
	cost(obj, container);
}

void	algorithm(t_container *container)
{
	int	i;
	int	smallest;
	int	little_cost;

	i = 0;
	little_cost = INT_MAX;
	while (i < container->index1)
	{
		container->array1[i].index = i;
		find_best(&container->array1[i], container);
		if (container->array1[i].cost < container->array1[smallest].cost)
			smallest = i;
		i++;
		//adesso sono in grado di trovare l'indice dove il cost è più piccolo,
		//ciò che mi manca è controllare/implementare che sia in grado di arrivare dallo zero al massimo
		//in tutti i casi, altrimenti mi si sfanculerà
	}
}