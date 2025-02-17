/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:16:21 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/15 17:46:47 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void	split_chunk(t_container *container, int ab_min, int max)
{
	int	i;
	int	size;
	int	min;
	int	mid;

	size = max - ab_min + 1;
	min = ab_min + (size / 3);
	mid = ab_min + (size * 2) / 3;
	i = 0;
	move_to_top(container, ab_min, max);
	while (i < size)
	{
		if (container->array1[0].sort <= min)
		{
			pb(container);
			rb(container);
		}
		else if (container->array1[0].sort <= mid)
			pb(container);
		else
			ra(container);
		i++;
	}
}

void	recursive_sort(t_container *container, int ab_min, int max)
{
	int	size;
	int	min;
	int	mid;

	size = (max - ab_min) + 1;
	min = ab_min + (size / 3);
	mid = ab_min + (size * 2) / 3;
	if (size <= 3)
		return (base_case(container, ab_min, max));
	split_chunk(container, ab_min, max);
	recursive_sort(container, mid + 1, max); //max
	recursive_sort(container, min + 1, mid); //mid
	recursive_sort(container, ab_min, min); //min
}

