/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:30:02 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/11/18 13:15:16 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb == 0)
		return (1);
	i = nb - 1;
	while (i > 0)
	{
		nb *= i;
		i--;
	}
	if (nb < 0)
		return (0);
	return (nb);
}
/*
#include <stdio.h>
int main()
{
	printf("%d", ft_iterative_factorial(9));
}*/
