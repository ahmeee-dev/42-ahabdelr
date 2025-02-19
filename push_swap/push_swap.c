/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:51:23 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/19 10:15:34 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	no_way(t_container *cont, int argc, char **argv)
{
	cont->type = 1;
	cont->array1 = array_creation(cont, argv, argc - 1);
	cont->array2 = (int *)malloc(sizeof(int) * (argc - 1));
	cont->index1 = argc - 1;
}

void	the_string(t_container *cont, char *argv)
{
	int		i;
	int		size;

	cont->type = 2;
	i = 0;
	size = 0;
	cont->str = ps_split(argv, ' ');
	while (cont->str[size] != NULL)
		size++;
	cont->index1 = size;
	cont->array1 = (int *)malloc(sizeof(int) * (size));
	while (i < size)
	{
		cont->array1[i] = push_swap_atoi(cont, cont->str[i], cont->array1);
		i++;
	}
	repeat_check(cont, cont->array1, size);
	cont->array2 = (int *)malloc(sizeof(int) * (size));
	i = 0;
	while (i < size)
	{
		free(cont->str[i]);
		i++;
	}
	free(cont->str);
}

int	main(int argc, char **argv)
{
	t_container	container;

	if (argc < 2)
		return (0);
	else if (argc > 2)
		no_way(&container, argc, argv);
	else if (argc == 2)
	{
		the_string(&container, argv[1]);
	}
	container.index2 = 0;
	container.count = 0;
	if (!(already_sorted(&container, container.index1, 1)))
	{
		if (container.index1 == 2)
			sa(&container);
		else if (container.index1 == 3)
			fast_sort_a(&container);
		else
			quick_sort_a(&container, container.index1);
	}
	free(container.array1);
	free(container.array2);
	return (0);
}

// ft_printf("\n\n");
// for (int i = 0; i < container.index1; i++)
// 	ft_printf("%d -", container.array1[i]);
// ft_printf("\n\n");
// ft_printf("Mosse richieste: %d", container.count);
// ft_printf("\n\n");
