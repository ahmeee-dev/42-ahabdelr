/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:59:20 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/27 15:44:56 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	print_death(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%lld %d died\n", (((long long)tv.tv_sec * 1000)
			+ ((long long)tv.tv_usec / 1000)), philo->number);
}

void	print_eat(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%lld %d is eating\n", (((long long)tv.tv_sec * 1000)
			+ ((long long)tv.tv_usec / 1000)), philo->number);
	philo->ate = ((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec / 1000);
}

void	print_sleep(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%lld %d is sleeping\n", (((long long)tv.tv_sec * 1000)
			+ ((long long)tv.tv_usec / 1000)), philo->number);
}

void	print_think(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%lld %d is thinking\n", (((long long)tv.tv_sec * 1000)
			+ ((long long)tv.tv_usec / 1000)), philo->number);
}

void	print_fork(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%lld %d has taken a fork\n", (((long long)tv.tv_sec * 1000)
			+ ((long long)tv.tv_usec / 1000)), philo->number);
}
