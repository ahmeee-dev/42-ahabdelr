/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:26:42 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/14 18:38:09 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int	*give_order(t_container *container, int *ordered)
{
	int	i;
	int	j;

	i = 0;
	while (i < container->size)
	{
		j = 0;
		while (j < container->size)
		{
			if (container->array1[i].value == ordered[j])
				container->array1[i].sort = j;
			j++;
		}
		i++;
	}
	return (ordered);
}

int	*oder_array(t_container *container)
{
	int	*ordered;
	int	i;
	int	temp;

	ordered = (int *)malloc(sizeof(int) * container->size);
	i = 0;
	while (i < container->size)
	{
		ordered[i] = container->array1[i].value;
		i++;
	}
	i = 0;
	while (i < container->size - 1)
	{
		if (ordered[i] > ordered[i + 1])
		{
			temp = ordered[i + 1];
			ordered[i + 1] = ordered[i];
			ordered[i] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (give_order(container, ordered));
}