/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:19:13 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/04 08:44:22 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_init(t_philo *philo, t_eat *eat)
{
	eat->phi_num = philo->data->ph_number;
	if (philo->number == 1)
		eat->prev = eat->phi_num - 1;
	else
		eat->prev = -1;
	if (philo->number == eat->phi_num)
		eat->next = 1 - eat->phi_num;
	else
		eat->next = +1;
}

int	check_death(t_philo *philo)
{
	struct timeval	tv;
	int				time;
	int				last_meal;

	gettimeofday(&tv, NULL);
	time = ((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec / 1000);
	last_meal = time - philo->ate;
	if (last_meal > philo->data->to_die)
	{
		print_death(philo);
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
	pthread_mutex_lock(&((philo)->mutex));
	print_fork(philo);
	pthread_mutex_lock(&((philo + eat.next)->mutex));
	print_fork(philo);
	if (!check_death(philo))
	{
		print_eat(philo);
		usleep(philo->data->to_eat);
	}
	pthread_mutex_unlock(&((philo + eat.next)->mutex));
	pthread_mutex_unlock(&((philo)->mutex));
	return (1);
}
