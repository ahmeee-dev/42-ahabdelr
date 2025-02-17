/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:06:33 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/17 14:56:27 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	ft_error(int *array)
{
	free(array);
	ft_printf("Error\n");
	exit(0);
}

void	repeat_check(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				ft_error(array);
			j++;
		}
		i++;
	}
}

int	push_swap_atoi(char *str, int *array)
{
	unsigned int		i;
	int			sign;
	unsigned long int	num;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(array);
		num = 10 * num + (str[i] - '0');
		i++;
	}
	if ((num > 2147483648 && sign == -1) || (num > 2147483647 && sign == 1))
		ft_error(array);
	return (num * sign);
}

int	*array_creation(char **numbers, int size)
{
	int	*array;
	int	i;
	
	i = 0;
	array = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		array[i] = push_swap_atoi(numbers[i + 1], array);
		i++;
	}
	repeat_check(array, size);
	return (array);
}