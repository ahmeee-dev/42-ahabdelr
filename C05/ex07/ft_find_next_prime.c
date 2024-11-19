/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:16:03 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/11/18 15:58:08 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_find_next_prime(int nb)
{
	int	alias;

	if (nb < 2)
		return (2);
	alias = nb - 1;
	while (alias > 1)
	{
		if (nb % alias == 0)
			return (ft_find_next_prime(nb + 1));
		else
			alias--;
	}
	return (nb);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_find_next_prime(1346));
	return 0;
}*/
