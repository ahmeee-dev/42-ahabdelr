/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:32:59 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/17 17:08:51 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	ra(t_container *container)
{
	int	temp;
	int	i;

	i = 0;
	if (container->index1 > 1)
	{
		temp = container->array1[0];
		while (i < container->index1 - 1)
		{
			container->array1[i] = container->array1[i + 1];
			i++;
		}
		container->array1[container->index1 - 1] = temp;
		ft_printf("ra\n");
	}
	container->count++;
}

void	rb(t_container *container)
{
	int	temp;
	int	i;

	i = 0;
	if (container->index2 > 1)
	{
		temp = container->array2[0];
		while (i < container->index2 - 1)
		{
			container->array2[i] = container->array2[i + 1];
			i++;
		}
		container->array2[container->index2 - 1] = temp;
		ft_printf("rb\n");
	}
	container->count++;
}

void	rr(t_container *container)
{
	ra(container);
	rb(container);
	ft_printf("rr\n");
	container->count--;
}