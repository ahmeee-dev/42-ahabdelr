/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:06:22 by marvin@42.f       #+#    #+#             */
/*   Updated: 2025/02/21 13:16:17 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct	s_data
{
	char	c;
	int	times;	
}		t_data;

t_data	data;

void	handler(int sig)
{
	if (sig == SIGUSR1)
		sig = 0;
	else if (sig == SIGUSR2)
		sig = 1;
	data.c <<= 1;
	data.c |= sig;
	data.times++;
	if (data.times % 32 == 0)
	{
		write(0, &c, 1);
		data.times = 0;	
		data.c = 0;
	}
}

int	main()
{
	struct sigaction sa;
	
	data.c = 0;
	data.times = 0;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	ft_printf("%d", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while(1)
		usleep(100);
	return (0);
}
