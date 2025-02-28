/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:09:50 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/28 21:40:22 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#endif

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_eat
{
	int	prev;
	int	next;
	int	actual;
	int	phi_num;
}		t_eat;

typedef struct	s_data
{
	pthread_mutex_t	mutex;
	pthread_mutex_t	check;
	int	alive;
	int	objective;
	int	to_eat;
	int	to_die;
	int	ph_number;
	int	to_sleep;
	int	times_eat;
}		t_data;

typedef struct	s_philo
{
	pthread_t	thread;
	int		number;
	int		ate;
	pthread_mutex_t	mutex;
	t_data		*data;
}		t_philo;

void	*routine(void *arg);
void	philosopher(t_data *data);
void	data_init(t_data *data, int argc, char **argv);
void	first_meal(t_philo *philo, t_data *data);
void	create_mutexes(t_philo *philo, t_data *data);
void	create_threads(t_philo *philo, t_data *data);
void	apocalipse(t_philo *philo, t_data *data);
void	eat_init(t_philo *philo, t_eat *eat);
int	check_death(t_philo *philo);
void	do_sleep(t_philo *philo);
int	eat(t_philo *philo);
void	print_death(t_philo *philo);
void	print_eat(t_philo *philo);
void	print_sleep(t_philo *philo);
void	print_think(t_philo *philo);
void	print_fork(t_philo *philo);
int	mytoi(char *str);