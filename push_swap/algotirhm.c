/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algotirhm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:29:04 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/10 19:44:34 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

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

void	moves_check(t_container *container, int k, int m)
{
	int	m_cost;
	int	k_cost;

	if (k >= (container->index1 / 2))
		k_cost = container->index1 - k;
	else
	{
		k_cost = k + 2;
		k = -1;
	}
	if (m >= (container->index1 / 2) + 1)
		m_cost = container->index1 - m + 1;
	else
	{
		m_cost = m + 2;
		m = -1;
	}
	if (m_cost < k_cost)
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
//problema 1: non è in grado di sortare
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
			i = -1;
		}
		i++;
		if (i == container->size - 1 && check == 1)
			i = 0;
	}
}

void	move_number(t_container *container)
{
	int	prev;
	int	next;
	order(container);
	for (int i = 0; i < container->size; i++)
		ft_printf("%i\n", container->ordered[i]);

	next = moves_number_next(container);
	prev = moves_number_prev(container);
	moves_check(container, next, prev);
	moves_exec(container);
	//devo ancora settare questo come un loop e testare tutto ciò che viene dopo order().
}