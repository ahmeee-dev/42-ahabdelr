/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algotirhm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:29:04 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/12 09:22:11 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

//dubbio nella riga 25, il resto sembra andare, da testare con numeri più grandi e con più numeri in generale.
int	m_func(t_container *container, int *m)
{
	int	m_cost;

	m_cost = INT_MAX;
	if (*m >= (container->index2 / 2) + 1 * (container->index2 % 2))
	{
		m_cost = container->index2 - (*m) + 1;
	}
	else if (*m >= 0)
	{
		m_cost = (*m) + 1;
		*m = -1;
	}
	return (m_cost);
}

int	k_func(t_container *container, int *k)
{
	int	k_cost;

	k_cost = INT_MAX;
	if (*k >= (container->index2 / 2))
	{
		k_cost = container->index2 - *k;
	}
	else if (*k >= 0)
	{
		k_cost = *k + 2;
		*k = -1;
	}
	return (k_cost);
}

void	moves_exec(t_container *container)
{
	int	direction;
	int	moves;

	moves = container->move.moves;
	direction = container->move.direction;
	if (direction %2 == 1)
	{
		while (moves > 1)
		{
			rev_rb(container);
			moves--;
		}
	}
	else
	{
		while (moves > 1)
		{
			rb(container);
			moves--;
		}
	}
	pb(container);
}

void	moves_check(t_container *container, int k_original, int m_original)
{
	int	m_cost;
	int	k_cost;
	int	k;
	int	m;

	m = m_original;
	k = k_original;
	k_cost = k_func(container, &k);
	m_cost = m_func(container, &m);
	if (m_cost > 0 && m_cost < k_cost)
	{
		container->move.moves = m_cost;
		container->move.direction = 4 * (m < 0) + 3 * (m >= 0);
	}
	else
	{
		container->move.moves = k_cost;
		container->move.direction = 2 * (k < 0) + 1 * (k >= 0);
	}
}

void	order(t_container *container)
{
	int	i;
	int	temp;

	i = 0;
	while (i < container->size - 1)
	{
		if (container->ordered[i] > container->ordered[i + 1])
		{
			temp = container->ordered[i + 1];
			container->ordered[i + 1] = container->ordered[i];
			container->ordered[i] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	first_last(t_container *container)
{
	int	size;
	
	size = container->size - 1;
	if (container->array1[0].value == container->ordered[size] && container->index1 > 1)
		ra(container);
}

void	move_number(t_container *container)
{
	int	prev;
	int	next;

	order(container);
	set_of_3(container);
	while (container->index1 > 0)
	{
		first_last(container);
		next = moves_number_next(container);
		prev = moves_number_prev(container);
		moves_check(container, next, prev);
		moves_exec(container);
	}
	while (container->index2 > 0)
		pa(container);
	//devo ancora settare questo come un loop e testare tutto ciò che viene dopo order().
}
