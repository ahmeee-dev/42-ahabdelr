/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:16:21 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/13 17:55:12 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void	base_case(t_container *container, int min, int max)
{

}

void	split_chunk(t_container *container, int ab_min, int max)
{
	int	i;
	int	size;
	int	min;
	int	mid;

	size = max - ab_min;
	min = ab_min + (size / 3);
	mid = ab_min + (size * 2) / 3;
	i = 0;
	if (container->array2[0].sort >= min && container->array2[0].sort <= max)
	{
		while (i < size)
		{
			pa(container);
			i++;
		}
	}
	i = 0;
	while (i < size)
	{
		if (container->array1[0].sort <= min)
		{
			pb(container);
			rev_rb(container);
		}
		else if (container->array1[0].sort <= mid)
			pb(container);
		else
			rev_ra(container);
		i++;
	}
	//se l'elemento che voglio è nei MAXmi trovo al bivio, se è a destra lo devo solo ruotare, altirmenti lo devo prima spostare e poi ruotare
}

void	recursive_sort(t_container *container, int ab_min, int max)
{
	int	size;
	int	min;
	int	mid;

	size = max - ab_min;
	min = ab_min + (size / 3);
	mid = ab_min + (size * 2) / 3;
	if (size <= 4)
		base_case(...);
	//il mio base case è un sort tendente al brute force per 4 elementi
	//pensavo di provare a espanderlo a 5, ma ho paura possa cominciare a costare anche quello
	split_chunk(container, ab_min, max);
	recursive_sort(container, mid + 1, max); //max
	recursive_sort(container, min + 1, mid); //mid
	recursive_sort(container, ab_min, min); //min
}

