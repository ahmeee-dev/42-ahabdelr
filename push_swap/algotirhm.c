/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algotirhm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:29:04 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/06 16:01:32 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

//da finire di creare una sorta di bubble sort ad hoc. ciò che manca è la
//ricorsività per riapplicare il processo fino al successo

void	algo(t_container *container)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (container->array1[0] > container->array1[container->index1 - 1])
		rev_ra(container);
	if (container->array1[0] > container->array1[1])
		sa(container);
	while (i < container->index1)
	{
		if (container->array1[i] > container->array1[i + 1])
		{
			while (j < i)
			{
				pa(container);
				j++;
			}
			sa(container);
			while (j > 0)
			{
				pb(container);
				j--;
			}
		}		
	}


}