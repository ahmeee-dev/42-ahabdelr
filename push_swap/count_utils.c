/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:48:38 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/12 09:19:48 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	moves_number_next(t_obj *obj, t_container *container)
{
	int	j;
	int	k;
	int	i;
	
	j = 0;
	k = 0;
	while (obj->value != container->ordered[j])
		j++;
	i = 1;
	while (j + i < container->size)
	{
		k = 0;
		while (k < container->index2)
		{
			if (container->array2[k].value == container->ordered[j + i])
				obj->b_index_next = k;
			k++;
		}
		i++;
	}
	obj->b_index_next = -1;
}


int	moves_number_prev(t_obj *obj, t_container *container)
{
	int	j;
	int	m;
	int	p;
	
	j = 0;
	m = 0;
	while (container->array1[0].value != container->ordered[j])
		j++;
	p = 1;
	while ((j - p) >= 0 && container->array2[m].value != container->ordered[j - p])
	{
		m = 0;
		while (m < container->index2)
		{
			if (container->array2[m].value == container->ordered[j - p])
				obj->b_index_prev = m;
			container->array2++;
		}
		p++;
	}
	obj->b_index_prev = -1;
}

void	position(t_obj *obj, t_container *container)
{
	moves_number_next(obj, container);
	moves_number_prev(obj, container);	
}
