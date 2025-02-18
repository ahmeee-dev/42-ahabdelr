/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:06:33 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/18 19:01:36 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>


//se ha una stringa come argomento e questa contiene una lettera non mi fa i dovuti free, 
void	ft_error(t_container *cont, int *array, char *string)
{
	(void)string;
	free(array);
	write(2, "Error\n", 6);
	if (cont->type == 2)
		free(cont->str);
	exit(0);
}

void	repeat_check(t_container *cont, int *array, int size)
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
				ft_error(cont, array, NULL);
			j++;
		}
		i++;
	}
}

int	push_swap_atoi(t_container *cont, char *str, int *array)
{
	unsigned int		i;
	int					sign;
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
			ft_error(cont, array, str);
		num = 10 * num + (str[i] - '0');
		i++;
	}
	if ((num > 2147483648 && sign == -1) || (num > 2147483647 && sign == 1))
		ft_error(cont, array, str);
	return (num * sign);
}

int	*array_creation(t_container *cont, char **numbers, int size)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		array[i] = push_swap_atoi(cont, numbers[i + 1], array);
		i++;
	}
	repeat_check(cont, array, size);
	return (array);
}
