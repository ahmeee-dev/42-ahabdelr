/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:43:28 by marvin@42.f       #+#    #+#             */
/*   Updated: 2025/02/11 14:05:59 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

//inverti first_sort()

void	first_sort(t_container *container)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = container->array2[0];
	n2 = container->array2[1];
	n3 = container->array2[2];
	if (n1 > n2 && n2 < n3 && n1 < n3)
		rev_rb(container);
	else if (n1 < n2 && n2 < n3 && n1 < n3)
	{
		sb(container);
		rev_rb(container);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
	{
		rev_rb(container);
		sb(container);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		sb(container);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
		rb(container);	
}


void	set_of_3(t_container *container)
{
	pb(container);
	pb(container);
	pb(container);
	first_sort(container);
}