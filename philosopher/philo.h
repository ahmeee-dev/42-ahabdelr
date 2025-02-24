/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:09:50 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/24 17:17:22 by ahabdelr         ###   ########.fr       */
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
	int		ate;

}		t_philo;

typedef struct	s_data
{
	int	to_eat;
	int	to_die;
	int	ph_number;
	int	to_sleep;
	int	times_eat;
}		t_data;

int	mytoi(char *str);