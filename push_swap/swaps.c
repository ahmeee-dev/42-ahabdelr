/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:39:14 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/17 17:08:25 by ahabdelr         ###   ########.fr       */
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
		ft_printf("sa\n");
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
		ft_printf("sb\n");
	}
	container->count++;
}

void	ss(t_container *container)
{
	sa(container);
	sb(container);
	ft_printf("ss\n");
	container->count--;
}
