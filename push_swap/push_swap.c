/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:51:23 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/11 14:08:12 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

//the debbugging session started from algorithm.c since it seems like the other functions are working well

int	*array_copy(int	*array1, int size)
{
	int	i;
	int	*res;

	i = 0;
	res = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		res[i] = array1[i];
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
	container.array2 = (int *)malloc(sizeof(int) * (argc - 1));
	container.ordered = array_copy(container.array1, argc - 1);
	container.size = argc - 1;
	container.index1 = argc - 1;
	container.index2 = 0;
	container.count = 0;
	move_number(&container);
	for (int i = 0; i < container.index1; i++)
		ft_printf("%i ", container.array1[i]);
	ft_printf("\n\n");
	for (int i = 0; i < container.index2; i++)
		ft_printf("%i ", container.array2[i]);
	return (0);
}
