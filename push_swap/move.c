/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:46:03 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/15 17:53:10 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void	move_from_bottom_b(t_container *container, int size)
{
	if (container->index2 > size)
	{
		while (size > 0)
		{
			rev_rb(container);
			pa(container);
			size--;
		}
	}
	else 
	{
		while (size > 0)
		{
			pa(container);
			size--;
		}	
	}
	return;
}

void	move_from_top_b(t_container *container, int size)
{
	while (size > 0)
	{
		pa(container);
		size--;
	}
	return;
}

void	move_from_bottom_a(t_container *container, int size)
{
	if (container->index1 > size)
	{
		while (size > 0)
		{
			rev_ra(container);
			size--;
		}
	}
	return;
}

void	move_to_top(t_container *container, int min, int max)
{
	int	size;
	int	index;

	size = (max - min) + 1;
	index = container->array2[container->index2 - 1].sort;
	if (index >= min && index <= max)
		return (move_from_bottom_b(container, size));
	index = container->array2[0].sort;
	if (index >= min && index <= max)
		return (move_from_top_b(container, size));
	index = container->array1[container->index1 - 1].sort;
	if (index >= min && index <= max)
		return (move_from_bottom_a(container, size));
}