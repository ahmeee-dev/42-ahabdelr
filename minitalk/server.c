/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:06:22 by marvin@42.f       #+#    #+#             */
/*   Updated: 2025/02/21 15:06:48 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct	s_data
{
	int	c;
	int	times;	
}		t_data;

t_data	data;

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		sig = 0;
	else if (sig == SIGUSR2)
		sig = 1;
	data.c <<= 1;
	data.c |= sig;
	data.times++;
	if (data.times % 8 == 0)
	{
		ft_printf("%c", data.c);
		data.times = 0;	
		data.c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main()
{
	struct sigaction sa;
	
	data.client_pid = 0;
	data.c = 0;
	data.times = 0;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while(1)
		usleep(100);
	return (0);
}
