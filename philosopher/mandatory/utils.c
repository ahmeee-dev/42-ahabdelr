/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:01:18 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/03 11:21:03 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mytoi(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
			return (-2);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	philo_check(t_data *data)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (data->ph_number == 1)
	{
		usleep(data->to_die * 1000);
		printf("%lld 1 is dead\n", (((long long)tv.tv_sec * 1000)
				+ ((long long)tv.tv_usec / 1000)));
		return (0);
	}
	if (data->to_die < 0 || data->to_eat < 0)
		return (printf("Bad input, only positive numbers") * 0);
	if (data->to_sleep < 0 || data->ph_number < 1)
		return (printf("Bad input, only positive numbers") * 0);
	if (data->objective < -1)
		return (printf("Bad input, only positive numbers") * 0);
	return (1);
}
