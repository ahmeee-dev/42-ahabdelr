/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:05:08 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/17 16:46:59 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int	quick_sort_b(t_container *container, int size)
{
	int	pivot;
	int	len;
	int	count;

	if (already_sorted(container, size, 2))
	{
		while (size--)
			pa(container);
		return (1);
	}
	if (size <= 3)
	{
		base_case_b(container, size);
		return (1); 
	}
	count = 0;
	len = size;
	pivot = get_middle(container->array2, size);
	while (size != len / 2)
	{
		if (container->array2[0] >= pivot && size--)
			pa(container);
		else if (++count)
			rb(container);
	}
	while (container->index2 != len / 2 && count--)
		rev_rb(container);
	return (quick_sort_a(container, len / 2 + len % 2) && quick_sort_b(container, len / 2));
	return (1);
}

int	quick_sort_a(t_container *container, int size)
{
	int	pivot;
	int	len;
	int	count;
	
	if (already_sorted(container, size, 1))
		return (1);
	if (size <= 3)
	{
		base_case_a(container, size);
		return (1); 
	}
	count = 0;
	len = size;
	pivot = get_middle(container->array1, size);
	while (size != len / 2 + len % 2)
	{
		if (container->array1[0] < pivot && size--)
			pb(container);
		else if (++count)
			ra(container);
	}
	while (container->index1 != len / 2 + len % 2 && count--)
		rev_ra(container);
	return (quick_sort_a(container, len / 2 + len % 2) && quick_sort_b(container, len / 2));
	return (1);
}