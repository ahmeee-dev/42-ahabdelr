/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:51:23 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/17 15:18:49 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_container	container;

	if (argc < 2)
		return (0);
	container.array1 = array_creation(argv, argc - 1);
	container.array2 = (int *)malloc(sizeof(int) * (argc - 1));
	container.index1 = argc - 1;
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
	ft_printf("\n\n");
	for (int i = 0; i < container.index1; i++)
		ft_printf("%d -", container.array1[i]);
	ft_printf("\n\n");
	for (int i = 0; i < container.index2; i++)
		ft_printf("%d -", container.array2[i]);
	ft_printf("Mosse richieste: %d", container.count);
	ft_printf("\n\n");
	return (0);
}
