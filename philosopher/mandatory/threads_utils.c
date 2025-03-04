/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:27:29 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/04 14:06:43 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	create_mutexes(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->mutex, NULL);
	pthread_mutex_init(&data->check, NULL);
	while (i < data->ph_number)
	{
		pthread_mutex_init(&philo[i].mutex, NULL);
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
		usleep(10);
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
	pthread_mutex_destroy(&((philo)->mutex));
}
