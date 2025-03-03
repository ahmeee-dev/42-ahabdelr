/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:27:29 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/03 14:09:46 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	first_meal(t_philo *philo, t_data *data)
{
	struct timeval	tv;
	int				i;
	int				time;

	data->alive = 1;
	gettimeofday(&tv, NULL);
	time = ((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec / 1000);
	i = 0;
	while (i < data->ph_number)
	{
		philo[i].ate = time;
		i++;
	}
}

void	create_processes(t_philo *philo, t_data *data)
{ 
	int	i;
	pid_t	pid;

	i = 0;
	pid = get_pid();
	sem_init(&data->check, 0, 1);
	sem_init(&philo->sem, 0, philo->data->ph_number);
	while (i < data->ph_number)
	{
		
	}
}

void	create_threads(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_number)
	{
		pthread_create(&philo[i].thread, NULL, routine, (void *)(philo + i));
		i++;
		usleep(1);
	}
}

void	apocalipse(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_number)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	sem_destroy(&((philo)->sem));
	sem_destroy(&data->check);
}
