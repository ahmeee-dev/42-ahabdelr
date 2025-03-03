/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:43:29 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/03 11:20:38 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = 0;
	while (i != philo->data->objective && philo->data->alive == 1)
	{
		if (!eat(philo))
		{
			philo->data->alive = 0;
			return (NULL);
		}
		if (philo->data->alive == 0)
			return (NULL);
		do_sleep(philo);
		i++;
	}
	return (NULL);
}

void	philosopher(t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->ph_number);
	first_meal(philo, data);
	create_mutexes(philo, data);
	create_threads(philo, data);
	apocalipse(philo, data);
	free(philo);
}

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
		philosopher(&data);
	return (0);
}
