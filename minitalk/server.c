/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:06:22 by marvin@42.f       #+#    #+#             */
/*   Updated: 2025/02/21 17:20:10 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

int	g_c;

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	times = 0;

	(void)context;
	if (sig == SIGUSR1)
		sig = 0;
	else if (sig == SIGUSR2)
		sig = 1;
	g_c <<= 1;
	g_c |= sig;
	times++;
	if (times % 8 == 0)
	{
		ft_printf("%c", g_c);
		times = 0;
		g_c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	g_c = 0;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while (1)
		usleep(1000);
	return (0);
}
