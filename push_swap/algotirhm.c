/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algotirhm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:29:04 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/10 12:00:44 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void	order(t_container *container)
{
	int	i;
	int	temp;
	int	check;

	i = 0;
	check = 1;
	while (check != 0)
	{
		check = 0;
		if (i < container->size - 1 && container->ordered[i] > container->ordered[i + 1])
		{
			temp = container->ordered[i + 1];
			container->ordered[i + 1] = container->ordered[i];
			container->ordered[i] = temp;
			check = 1;
		}
		i++;
		if (i == container->size - 1 && check == 1)
			i = 0;
	}
}

int	moves_check(t_container *container)
{
	int	j;
	int	k;
	int	m;
	int	m_cost;
	int	k_cost;

	j = 0;
	k = 0;
	m = 0;
	//aggiungi per il caso in cui non sia il primo successivo o precedente 
	// ma il secondo o così a salire
	while (container->array1[0] != container->ordered[j])
		j++;
	while (j < container->size - 1 &&  container->array2[k] != container->ordered[j + 1])
		k++;
	while (j > 0 &&  container->array2[k] != container->ordered[j - 1])
		m++;
	if (k >= (container->index2 / 2))
	{
		k_cost = container->index2 - k;
		container->direction = 1;
	}
	else
	{
		k_cost = k + 2;
		container->direction = 2;
	}
	if (m >= (container->index2 / 2) + 1)
	{
		m_cost = container->index2 - m + 1;
		container->direction = 3;
	}
	else 
	{
		m_cost = m + 2;
		container->direction = 4;
	}
}

void	algo(t_container *container)
{
	
}