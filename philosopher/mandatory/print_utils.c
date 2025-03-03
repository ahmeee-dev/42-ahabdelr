/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:59:20 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/03 11:20:46 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_death(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->alive == 1)
	{
		printf("%lld %d died\n", (((long long)tv.tv_sec * 1000)
				+ ((long long)tv.tv_usec / 1000)), philo->number);
	}
	philo->data->alive = 0;
	pthread_mutex_unlock(&philo->data->mutex);
}

void	print_eat(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->alive == 1)
	{
		printf("%lld %d is eating\n", (((long long)tv.tv_sec * 1000)
				+ ((long long)tv.tv_usec / 1000)), philo->number);
	}
	pthread_mutex_unlock(&philo->data->mutex);
	philo->ate = ((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec / 1000);
}

void	print_sleep(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->alive == 1)
	{
		printf("%lld %d is sleeping\n", (((long long)tv.tv_sec * 1000)
				+ ((long long)tv.tv_usec / 1000)), philo->number);
	}
	pthread_mutex_unlock(&philo->data->mutex);
}

void	print_think(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->alive == 1)
	{
		printf("%lld %d is thinking\n", (((long long)tv.tv_sec * 1000)
				+ ((long long)tv.tv_usec / 1000)), philo->number);
	}
	pthread_mutex_unlock(&philo->data->mutex);
}

void	print_fork(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->alive == 1)
	{
		printf("%lld %d has taken a fork\n", (((long long)tv.tv_sec * 1000)
				+ ((long long)tv.tv_usec / 1000)), philo->number);
	}
	pthread_mutex_unlock(&philo->data->mutex);
}
