/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:48:57 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/11/18 15:02:02 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	max;

	max = nb / 2;
	if (nb == 1)
		return (1);
	while (max > 0)
	{
		if (max * max == nb)
			return (max);
		else
			max--;
	}
	return (0);
}
/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_sqrt(169));
	return 0;
}*/
