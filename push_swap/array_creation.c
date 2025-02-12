/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:06:33 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/12 08:34:07 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

t_obj	*array_creation(char **numbers, int size)
{
	t_obj	*array;
	int	i;

	i = 0;
	array = (t_obj *)malloc(sizeof(t_obj) * size);
	while (i < size)
	{
		array[i].value = atoi(numbers[i + 1]);
		i++;
	}
	return (array);
}