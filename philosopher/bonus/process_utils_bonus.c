/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:27:29 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/04 13:44:03 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	closure(t_data *data)
{
	sem_close(data->check);
	sem_close(data->print);
	sem_unlink("/sem");
	sem_unlink("/print");
}

void	process_creation(t_data *data)
{
	pid_t	pid;
	int		i;

	i = 0;
	sem_unlink("/sem");
	sem_unlink("/print");
	sem_unlink("/order");
	data->check = sem_open("/sem", O_CREAT | O_RDWR, 0666, data->ph_number);
	data->print = sem_open("/print", O_CREAT | O_RDWR, 0666, 1);
	data->order = sem_open("/order", O_CREAT | O_RDWR, 0666, 1);
	while (i < data->ph_number)
	{
		pid = fork();
		if (pid == 0)
		{
			routine(i, data);
			sem_close(data->check);
			sem_close(data->print);
			sem_close(data->order);
			exit(0);
		}
		i++;
		usleep(1);
	}
	i = 0;
	while (i++ < data->ph_number)
		waitpid(-1, NULL, 0);
	closure(data);
}
