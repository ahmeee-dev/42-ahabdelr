/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:39:14 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/07 14:50:28 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	sa(t_container *container)
{
	int	temp;

	if (container->array1[0] && container->array1[1])
	{
		temp = container->array1[0];
		container->array1[0] = container->array1[1];
		container->array1[1] = temp;
	}
	container->count++;
}

void	sb(t_container *container)
{
	int	temp;

	if (container->array2[0] && container->array2[1])
	{
		temp = container->array2[0];
		container->array2[0] = container->array2[1];
		container->array2[1] = temp;
	}
	container->count++;
}

void	ss(t_container *container)
{
	sa(container);
	sb(container);
	container->count--;
}
