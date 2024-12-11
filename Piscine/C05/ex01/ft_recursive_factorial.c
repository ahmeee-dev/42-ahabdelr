/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:02:40 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/11/18 13:17:00 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	else if (nb > 1)
		nb *= ft_recursive_factorial(nb - 1);
	return (nb);
}

/* #include <stdio.h>
int main()
{
	printf("%d\n", ft_recursive_factorial(5));
	return 0;
}*/
