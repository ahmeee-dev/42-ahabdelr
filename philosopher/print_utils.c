/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:59:20 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/26 10:32:32 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo.h"

void	print_death(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%lld %d died", (((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec/1000)), philo->number);
	exit(0); //da sostituire con la free function 🆓
}

void	print_eat(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%lld %d is eating", (((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec/1000)), philo->number);
	philo->ate = ((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec/1000);
}

void	print_sleep(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%lld %d is sleeping", (((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec/1000)), philo->number);
}

void	print_think(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%lld %d is thinking", (((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec/1000)), philo->number);
}

void	print_fork(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%lld %d has take a fork", (((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec/1000)), philo->number);
}
