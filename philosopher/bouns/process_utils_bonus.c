/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:27:29 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/03 16:59:11 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	process_creation(t_data *data)
{
	pid_t	parent_pid;
	pid_t	pid;
	sem_t	*sem;
	int	i;

	i = 0;
	parent_pid = getpid();
	sem = sem_open("/sem", O_CREAT | O_RDWR, 0666, data->ph_number);
	while (i < data->ph_number)
	{
		pid = fork();
		routine(i, data);
		i++;
	}
	//adesso aggiungo la pparte che aspetta finisca e che poi cancelli tutto
}
