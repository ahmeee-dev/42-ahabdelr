/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:35:26 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/07 14:51:13 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	rev_ra(t_container *container)
{
	int	i;
	int	temp;

	i = container->index1 - 1;
	if (i > 0)
	{
		temp = container->array1[container->index1 - 1];
		while (i > 0)
		{
			container->array1[i] = container->array1[i - 1];
			i--;
		}
		container->array1[0] = temp;
	}
	container->count++;
}

void	rev_rb(t_container *container)
{
	int	i;
	int	temp;

	i = container->index2 - 1;
	if (i > 0)
	{
		temp = container->array2[container->index2 - 1];
		while (i > 0)
		{
			container->array2[i] = container->array2[i - 1];
			i--;
		}
		container->array2[0] = temp;
	}
	container->count++;
}

void	rev_rr(t_container *container)
{
	rev_ra(container);
	rev_rb(container);
	container->count--;
}