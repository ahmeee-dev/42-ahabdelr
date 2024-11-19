/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:04:27 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/11/18 15:15:14 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	alias;

	if (nb <= 1)
		return (0);
	alias = nb - 1;
	while (alias > 1)
	{
		if (nb % alias == 0)
			return (0);
		else
			alias--;
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_is_prime(13));
	return 0;
}*/
