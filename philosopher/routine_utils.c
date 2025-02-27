/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:19:13 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/27 15:46:12 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	eat_init(t_philo *philo, t_eat *eat)
{
	eat->phi_num = philo->data->ph_number;
	
	if (philo->number == 1)
		eat->prev = eat->phi_num - 1;
	else
		eat->prev = eat->actual - 1;
	if (philo->number == eat->phi_num)
		eat->next = 1 - eat->phi_num;
	else
		eat->next = philo->number + 1;
}

int	check_death(t_philo *philo)
{
	struct timeval tv;
	int time;
	int last_meal;

	gettimeofday(&tv, NULL);
	time = ((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec / 1000);
	last_meal = time - philo->ate;
	if (last_meal > philo->data->to_die)
	{
		print_death(philo);
		philo->data->alive = 0;
		return (1);
	}
	return (0);
}

void	do_sleep(t_philo *philo)
{
	print_sleep(philo);
	usleep(philo->data->to_sleep);
	print_think(philo);
}

int	eat(t_philo *philo)
{
	t_eat	eat;

	eat_init(philo, &eat);
	pthread_mutex_lock(&((philo + eat.next)->mutex));
	print_fork(philo);
	pthread_mutex_lock(&((philo + eat.prev)->mutex));
	print_fork(philo);
	if (check_death(philo))
		return (0);
	print_eat(philo);
	usleep(philo->data->to_eat);
	pthread_mutex_unlock(&((philo + eat.prev)->mutex));
	pthread_mutex_unlock(&((philo + eat.next)->mutex));
	return (1);
}