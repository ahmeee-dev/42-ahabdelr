/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:43:29 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/24 17:26:50 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

void	philosopher(t_data data)
{
	t_philo	threads[data.ph_number]; 

	
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc < 4)
		return (0);
	data.ph_number = mytoi(argv[1]);
	data.to_die = mytoi(argv[2]);
	data.to_sleep = mytoi(argv[3]);
}