/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:43:29 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/04 09:41:05 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	data_init(t_data *data, int argc, char **argv)
{
	data->ph_number = mytoi(argv[1]);
	data->to_die = mytoi(argv[2]);
	data->to_eat = mytoi(argv[3]) * 1000;
	data->to_sleep = mytoi(argv[4]) * 1000;
	if (argc == 6)
		data->objective = mytoi(argv[5]);
	else
		data->objective = -1;
	data->alive = 1;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 4)
		return (0);
	data_init(&data, argc, argv);
	if (philo_check(&data))
		process_creation(&data);
	return (0);
}
