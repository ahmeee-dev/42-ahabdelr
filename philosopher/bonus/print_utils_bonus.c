/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:59:20 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/04 10:32:39 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_death(int i, t_data *data)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	sem_wait(data->print);
	if (data->alive == 1)
	{
		printf("%lld %d died\n", (((long long)tv.tv_sec * 1000)
				+ ((long long)tv.tv_usec / 1000)), i);
	}
	data->alive = 0;
	sem_post(data->print);
}

void	print_eat(int i, t_data *data, int *last_meal)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	sem_wait(data->print);
	if (data->alive == 1)
	{
		printf("%lld %d is eating\n", (((long long)tv.tv_sec * 1000)
				+ ((long long)tv.tv_usec / 1000)), i);
	}
	*last_meal = (((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec
				/ 1000));
	sem_post(data->print);
}

void	print_sleep(int i, t_data *data)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	sem_wait(data->print);
	if (data->alive == 1)
	{
		printf("%lld %d is sleeping\n", (((long long)tv.tv_sec * 1000)
				+ ((long long)tv.tv_usec / 1000)), i);
	}
	sem_post(data->print);
}

void	print_think(int i, t_data *data)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	sem_wait(data->print);
	if (data->alive == 1)
	{
		printf("%lld %d is thinking\n", (((long long)tv.tv_sec * 1000)
				+ ((long long)tv.tv_usec / 1000)), i);
	}
	sem_post(data->print);
}

void	print_fork(int i, t_data *data)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	sem_wait(data->print);
	if (data->alive == 1)
	{
		printf("%lld %d has taken a fork\n", (((long long)tv.tv_sec * 1000)
				+ ((long long)tv.tv_usec / 1000)), i);
	}
	sem_post(data->print);
}
