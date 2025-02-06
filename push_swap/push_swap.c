/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:51:23 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/06 15:01:11 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	*array1;
	int	*array2;
	t_container	container;

	if (argc < 2)
		return (0);
	array1 = array_creation(argv, argc - 1);
	array2 = (int *)malloc(sizeof(int) * (argc - 1));
	container.array1 = array1;
	container.array2 = array2;
	container.size = argc - 1;
	container.index1 = argc - 1;
	container.index2 = 0;
	pb(&container);
	pb(&container);
	ss(&container);
	for (int i = 0; i < container.index1; i++)
		ft_printf("%i", container.array1[i]);
	ft_printf("\n");
	for (int i = 0; i < container.index2; i++)
		ft_printf("%i", container.array2[i]);
	ft_printf("\n");
	return (0);
}