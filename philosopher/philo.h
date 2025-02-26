/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:09:50 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/26 15:46:17 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#endif

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_philo
{
	pthread_t	thread;
	int		number;
	int		ate;
	pthread_mutex_t	mutex;
	t_data		*data;
}		t_philo;

typedef struct	s_data
{
	int	status;
	int	objective;
	int	to_eat;
	int	to_die;
	int	ph_number;
	int	to_sleep;
	int	times_eat;
}		t_data;

int	mytoi(char *str);
void	print_think(t_philo *philo);
void	print_die(t_philo *philo);
void	print_eat(t_philo *philo);
void	print_fork(t_philo *philo);
void	print_sleep(t_philo *philo);
void	my_mutex_unlock(t_philo *philo, int ph_n);
