/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:39:51 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/17 16:38:04 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	fast_sort_a(t_container *n)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = n->array1[0];
	n2 = n->array1[1];
	n3 = n->array1[2];
	if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		sa(n);
		rev_ra(n);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(n);
	else if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(n);
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rev_ra(n);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(n);
		ra(n);
	}
}

int	already_sorted(t_container *container, int size, int type)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (container->array1[i - 1] > container->array1[i] && type == 1) 
			return (0);
		else if (container->array2[i - 1] < container->array2[i] && type == 2)
			return (0);
		i++;
	}
	return (1);
}

int	get_middle(int *array, int size)
{
	int	i;
	int	*ordered;
	int	temp;
	int	pivot;

	i = 0;
	ordered = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		ordered[i] = array[i];
		i++;
	}
	i = 1;
	while (i < size)
	{
		if (ordered[i - 1] > ordered[i])
		{
			temp = ordered[i - 1];
			ordered[i - 1] = ordered[i];
			ordered[i] = temp;
			i = 0;
		}
		i++;
	}
	pivot = ordered[size / 2];
	free(ordered);
	return (pivot);
}