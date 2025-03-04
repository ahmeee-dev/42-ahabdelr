/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:19:13 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/04 13:48:22 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(int i, t_data *data, int *last_meal)
{
	check_deat(i, data, last_meal);
	sem_wait(data->order);
	sem_wait(data->check);
	print_fork(i, data);
	sem_wait(data->check);
	print_fork(i, data);
	sem_post(data->order);
	check_deat(i, data, last_meal);
	print_eat(i, data, last_meal);
	usleep(data->to_eat);
	sem_post(data->check);
	sem_post(data->check);
}

void	do_sleep(int i, t_data *data)
{
	print_sleep(i, data);
	usleep(data->to_sleep);
	print_think(i, data);
}

void	routine(int i, t_data *data)
{
	struct timeval	tv;
	int				time;
	int				times;

	gettimeofday(&tv, NULL);
	time = ((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec / 1000);
	times = 0;
	while (times != data->objective && data->alive == 1)
	{
		eat(i, data, &time);
		do_sleep(i, data);
		i++;
		times++;
	}
}

int	check_deat(int i, t_data *data, int *last_meal)
{
	struct timeval	tv;
	int				actual;
	int				last;

	gettimeofday(&tv, NULL);
	actual = (((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec / 1000));
	last = actual - (*last_meal);
	if (last > data->to_die)
	{
		print_death(i, data);
		return (0);
	}
	return (1);
}
