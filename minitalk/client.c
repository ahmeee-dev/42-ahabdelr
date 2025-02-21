/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:11:15 by marvin@42.f       #+#    #+#             */
/*   Updated: 2025/02/21 13:09:47 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	scompose_bits(int c, int pid)
{
	int	i;
	int	bit;
	
	i = 31;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		i--;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	char nl = '\n';
	
	if (argc != 3)
		return (1);
	i = 0;
	scompose_bits(nl, ft_atoi(argv[1]));
	while (argv[2][i] != '\0')
	{
		scompose_bits(argv[2][i], ft_atoi(argv[1]));
		i++;
	}

	scompose_bits(nl, ft_atoi(argv[1]));
	return (0);
}
