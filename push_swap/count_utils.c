/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:48:38 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/11 12:39:48 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

// da ricontrollare i casi in cui si è alla fine per il next o all'inizio per il prev

int	moves_number_next(t_container *container)
{
	int	j;
	int	k;
	int	i;
	
	j = 0;
	k = 0;
	while (container->array1[0] != container->ordered[j])
		j++;
	i = 1;
	while (j + i < container->size)
	{
		k = 0;
		while (k < container->index2)
		{
			if (container->array2[k] == container->ordered[j + i])
				return (k);
			k++;
		}
		i++;
	}
	return (-1);
}


int	moves_number_prev(t_container *container)
{
	int	j;
	int	m;
	int	p;
	
	j = 0;
	m = 0;
	while (container->array1[0] != container->ordered[j])
		j++;
	p = 1;
	while ((j - p) >= 0 && container->array2[m] != container->ordered[j - p])
	{
		m = 0;
		while (m < container->index2)
		{
			if (container->array2[m] == container->ordered[j - p])
				return (m);
			m++;
		}
		p++;
	}
	return (-1);
}
