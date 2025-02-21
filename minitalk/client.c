/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:11:15 by marvin@42.f       #+#    #+#             */
/*   Updated: 2025/02/21 17:13:24 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

int	g_check;

//ft_printf("x");
void	checker(int sig)
{
	(void)sig;
	g_check = 1;
}

void	scompose_bits(int c, int pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		g_check = 0;
		bit = (c >> i) & 1;
		i--;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_check == 0)
			pause();
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (1);
	g_check = 0;
	i = 0;
	signal(SIGUSR1, checker);
	while (argv[2][i] != '\0')
	{
		scompose_bits(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
	return (0);
}
