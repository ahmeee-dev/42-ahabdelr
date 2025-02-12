/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:39:14 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/12 08:32:42 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	sa(t_container *container)
{
	t_obj	temp;

	if (container->array1[0].value && container->array1[1].value)
	{
		temp = container->array1[0];
		container->array1[0] = container->array1[1];
		container->array1[1] = temp;
	}
	container->count++;
}

void	sb(t_container *container)
{
	t_obj	temp;

	if (container->array2[0].value && container->array2[1].value)
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
