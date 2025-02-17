/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:43:07 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/15 17:26:00 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	sort_three_top_b(t_container *container, int min, int max)
{
	(void)max;
	if (container->array2[0].sort == min)
		sb(container);
	pa(container);
	if (container->array2[0].sort == min)
		sb(container);
	pa(container);
	if (container->array1[0].sort > container->array1[1].sort)
		sa(container);
	pa(container);
}

void	sort_three_bottom_b(t_container *container, int min, int max)
{
	if (container->index2 > 3)
	{
		rev_rb(container);
		rev_rb(container);
		rev_rb(container);
	}
	sort_three_top_b(container, min, max);
}

void	sort_three_bottom_a(t_container *container, int min, int max)
{
	if (container->index1 > 3)
	{
		rev_ra(container);
		rev_ra(container);
		rev_ra(container);
	}
	sort_three_top_a(container, min, max);
}

void	sort_three_top_a(t_container *container, int min, int max)
{
	if (container->array1[0].sort == min && container->array1[1].sort == max)
	{
		ra(container);
		sa(container);
		rev_ra(container);
	}
	else if (container->array1[0].sort == max)
	{
		if (container->array1[1].sort == min)
		{
			sa(container);
			ra(container);
			sa(container);
			rev_ra(container);
		}
		else 
		{
			sa(container);
			ra(container);
			sa(container);
			rev_ra(container);
			sa(container);
		}
	}
	else if (container->array1[0].sort != max && container->array1[0].sort != min)
	{
		if (container->array1[1].sort == max)
		{
			ra(container);
			sa(container);
			rev_ra(container);
		}
		sa(container);
	}
}