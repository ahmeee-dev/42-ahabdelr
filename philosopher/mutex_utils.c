/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:42:48 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/26 16:12:09 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// 0 è dispari, 1 è pari
void	my_mutex_unlock(t_philo *philo, int ph_n)
{
	if (philo->number == 1 && ph_n % 2)
		pthread_mutex_unlock(&(philo + ph_n - 1)->mutex);
	if (philo->data->status == 0 && ph_n % 2 && philo->number == ph_n)
	{
		pthread_mutex_unlock(&(philo - 1)->mutex);
		philo->data->status = 1;
	}
	if (philo->data->status == 0 && !(ph_n % 2) && philo->number == ph_n - 1)
	{
		pthread_mutex_unlock(&(philo - 1)->mutex);
		philo->data->status = 1;
	}
	else if (philo->data->status == 1 && !(ph_n % 2) && philo->number == ph_n)
	{
		pthread_mutex_unlock(&(philo - 1)->mutex);
		philo->data->status = 0;
	}
	else if (philo->data->status == 1 && (ph_n % 2) && philo->number == ph_n
		- 1)
	{
		pthread_mutex_unlock(&(philo - 1)->mutex);
		philo->data->status = 0;
	}
}