/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:34:15 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/16 15:31:52 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	sort_1(t_container *container, int min)
{
	if (container->array1[0].sort == min)
		return;
	else if (container->array2[0].sort == min)
		return (pa(container));
	else if (container->array2[container->index2 - 1].sort == min)
	{
		rev_rb(container);
		pa(container);
	}
	else if (container->array1[container->index1 - 1].sort == min)
		rev_ra(container);
}

void	sort_2(t_container *container, int min, int max)
{
	move_to_top(container, min, max);
	if (container->array1[0].sort > container->array1[1].sort)
		sa(container);
}

void	sort_3(t_container *container, int min, int max)
{
	int	index;

	index = container->array1[0].sort;
	if (index >= min && index <= max)
		return (sort_three_top_a(container, min, max));
	index = container->array1[container->index1 - 1].sort;
	if (index >= min && index <= max)
		return (sort_three_bottom_a(container, min, max));
	index = container->array2[0].sort;
	if (index >= min && index <= max)
		return (sort_three_top_b(container, min, max));
	index = container->array2[container->index2 - 1].sort;
	if (index >= min && index <= max)
		return (sort_three_bottom_b(container, min, max));
}

// Testare, se necessario poi creare la funzione di sort_4

void	base_case(t_container *container, int min, int max)
{
	int	size;
	
	size = max - min + 1;
	if (size == 2)
		sort_2(container, min, max);
	else if (size == 3)
		sort_3(container, min, max);
	else if (size == 1)
		sort_1(container, min);
}