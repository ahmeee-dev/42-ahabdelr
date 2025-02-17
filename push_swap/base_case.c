/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:31:12 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/17 16:33:51 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int	base_case_b(t_container *s, int size)
{
	if (size == 1)
		pa(s);
	if (size == 2 && s->array2[0] < s->array2[1])
	{
		sb(s);
		pa(s);
		pa(s);
	}
	else if (size == 3)
	{
		while (size || !(s->array1[0] < s->array1[1] && s->array1[1] < s->array1[2]))
		{
			if (size == 1 && s->array1[0] > s->array1[1])
				sa(s);
			else if ((size == 1 || (size >= 2 && s->array2[0] > s->array2[1]) || (size == 3 && s->array2[0] >  s->array2[2])) && size--)
				pa(s);
			else
				sb(s);
		}
	}
	return (1);
}

void	sort_three_a(t_container *s, int size)
{
	while (size != 3 || !(s->array1[0] < s->array1[1] && s->array1[1] < s->array1[2]))
	{
		if (size == 3 && s->array1[0] > s->array1[1] && s->array1[2])
			sa(s);
		else if (size == 3 && !(s->array1[2] > s->array1[0] && s->array1[2] > s->array1[1]) && size--)
			pb(s);
		else if (s->array1[0] > s->array1[1])
			sa(s);
		else if (size++)
			pa(s);
	}
}

int	base_case_a(t_container *container, int size)
{
	if (size == 3 && container->index1 == 3)
		fast_sort_a(container);
	if (size == 2 && container->array1[0] > container->array1[1])
		sa(container);
	else if (size == 3)
		sort_three_a(container, size);
	return (1);
}