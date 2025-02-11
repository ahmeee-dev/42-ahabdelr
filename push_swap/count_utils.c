/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:48:38 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/11 09:45:17 by marvin@42.f      ###   ########.fr       */
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
	while (j + i <= container->index2 - 1 && container->array2[k] != container->ordered[j + i])
	{
		k++;
		if ((k == container->index2 - 1) && container->array2[k] != container->ordered[j + i])
		{
			i++;
			k = 0;
		}
	}
	return (k);
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
	while (j - p >= 0 && container->array2[m] != container->ordered[j - p])
	{
		m++;
		if ((m == container->index2 - 1) && container->array2[m] != container->ordered[j - p])
		{
			p++;
			m = 0;
		}
	}
	return (m);
}
