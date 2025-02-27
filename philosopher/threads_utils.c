/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:27:29 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/27 15:48:11 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	first_meal(t_philo *philo, t_data *data)
{
	struct timeval tv;
	int	i;
	int	time;

	gettimeofday(&tv, NULL);
	time = ((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec / 1000);
	i = 0;
	while (i < data->ph_number)
	{
		philo[i].ate = time;
		i++;
	}
}
void	create_mutexes(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_number)
	{
		pthread_mutex_init(&philo->mutex, NULL);
		philo[i].data = data;
		philo[i].number = i + 1;
		i++;
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
	i = 0;
	while (i < data->ph_number)
	{
		pthread_mutex_destroy(&((philo + i)->mutex));
		i++;
	}
}