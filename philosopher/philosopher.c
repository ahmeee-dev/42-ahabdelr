/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:43:29 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/26 16:30:39 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

void	do_sleep(t_philo *philo)
{
	print_sleep(philo);
	usleep(philo->data->to_sleep);
	print_think(philo);
}

//devo creare un mutex_lock
//devo trovare il modo di bloccare l'ultimo in caso abbia i dispari
// il problema è che rimarrei bloccato alla riga 38 se lockassi da un'altra parte
//  allo stesso tempo però così non ha lock sull'ultimo, quindi continuerebbe a girare
 
void	eat(t_philo *philo)
{
	int	ph_n;

	ph_n = philo->data->ph_number;
	pthread_mutex_lock(&philo->mutex) + pthread_mutex_unlock(&philo->mutex);
	if (philo->data->status == 0 && philo->number == 1)
	{
		pthread_mutex_lock(&(philo + 1)->mutex);
		if (ph_n % 2)
			pthread_mutex_lock(&(philo + ph_n - 1)->mutex);
	}
	else if (philo->data->status == 1 && philo->number == 2)
	{
		pthread_mutex_lock(&(philo - 1)->mutex);	
	}
	print_fork(philo);
	print_eat(philo);
	usleep(philo->data->to_eat);
	my_mutex_unlock(philo, ph_n);
}

void	routine(t_philo *philo)
{
	int	i;

	i = 0;
	while(i != philo->data->objective)
	{
		eat(philo);
		do_sleep(philo);
		i++;
	}
}

void	philosopher(t_data data)
{
	t_philo	philo[data.ph_number];
	pthread_mutex_t	mutex1;
	pthread_mutex_t	mutex2;
	pthread_mutex_t	mutexOdd;
	int	i;

	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);
	pthread_mutex_init(&mutexOdd, NULL);
	i = 0;
	philo->data = &data;
	while (i < data.ph_number)
	{
		if (!(i % 2))
			philo->mutex = mutex1;
		else
			philo->mutex = mutex2;
		i++;
		philo->number = i;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc < 4)
		return (0);
	data.ph_number = mytoi(argv[1]);
	data.to_die = mytoi(argv[2]);
	data.to_sleep = mytoi(argv[3]);
	if (argc == 5)
		data.objective = mytoi(argv[4]);
	else	
		data.objective = -1;
}