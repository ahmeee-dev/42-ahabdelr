/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:18:22 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/18 13:21:38 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	get_low1(t_container *container)
{
	int	i;

	i = container->index1;
	while (i > 0)
	{
		container->array1[i] = container->array1[i - 1];
		i--;
	}
}

void	get_low2(t_container *container)
{
	int	i;

	i = container->index2;
	while (i > 0)
	{
		container->array2[i] = container->array2[i - 1];
		i--;
	}
}

void	get_up1(t_container *container)
{
	int	i;

	i = 0;
	while (i < container->index1)
	{
		container->array1[i] = container->array1[i + 1];
		i++;
	}
}

void	get_up2(t_container *container)
{
	int	i;

	i = 0;
	while (i < container->index2)
	{
		container->array2[i] = container->array2[i + 1];
		i++;
	}
}
