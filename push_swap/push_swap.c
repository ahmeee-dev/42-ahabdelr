/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:51:23 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/13 14:47:31 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

//the debbugging session started from algorithm.c since it seems like the other functions are working well

int	*array_copy(t_obj *array1, int size)
{
	int	i;
	int	*res;

	i = 0;
	res = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		res[i] = array1[i].value;
		i++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	t_container	container;

	if (argc < 2)
		return (0);
	container.array1 = array_creation(argv, argc - 1);
	container.array2 = (t_obj *)malloc(sizeof(t_obj) * (argc - 1));
	container.size = argc - 1;
	container.index1 = argc - 1;
	container.index2 = 0;
	container.ordered = oder_array(&container);
	container.count = 0;
	ft_printf("\n\n");
	for (int i = 0; i < container.index1; i++)
		ft_printf("%i ", container.array1[i].value);
	ft_printf("\n\n");
	ft_printf("Mosse richieste: %d", container.count);
	ft_printf("\n\n");
	return (0);
}
