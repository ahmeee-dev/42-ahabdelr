/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:54:17 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/07 14:51:28 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	pa(t_container *container)
{
	if (container->index2)
	{
		get_low1(container);
		container->array1[0] = container->array2[0];
		container->index2 -= 1;
		container->index1 += 1;
		get_up2(container);
	}
	container->count++;
}

void	pb(t_container *container)
{
	if (container->index1)
	{
		get_low2(container);
		container->array2[0] = container->array1[0];
		container->index1 -= 1;
		container->index2 += 1;
		get_up1(container);
	}
	container->count++;
}