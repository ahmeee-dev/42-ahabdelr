/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:03:42 by marvin@42.f       #+#    #+#             */
/*   Updated: 2025/02/05 14:03:43 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>

void	trans_x(t_data *data, int i)
{
	data->news.y = data->matrix[i].y * cos(rad(data->vector->tx))
		- (data->matrix[i].z + (data->matrix[i].z != 0) * data->vector->trans_z)
		* sin(rad(data->vector->tx));
	data->news.z = data->matrix[i].y * sin(rad(data->vector->tx))
		+ (data->matrix[i].z + (data->matrix[i].z != 0) * data->vector->trans_z)
		* cos(rad(data->vector->tx));
	data->news.x = data->matrix[i].x;
}

void	trans_y(t_data *data)
{
	float	x;
	float	z;

	x = data->news.x;
	z = data->news.z;
	data->news.x = x * cos(rad(data->vector->ty)) - z
		* sin(rad(data->vector->ty));
	data->news.z = -x * sin(rad(data->vector->ty)) + z
		* cos(rad(data->vector->ty));
}

void	trans_z(t_data *data)
{
	float	x;
	float	y;

	y = data->news.y;
	x = data->news.x;
	data->news.x = x * cos(rad(data->vector->tz)) - y
		* sin(rad(data->vector->tz));
	data->news.y = x * sin(rad(data->vector->tz)) + y
		* cos(rad(data->vector->tz));
}

void	rotate(t_data *data, int i)
{
	trans_x(data, i);
	trans_y(data);
	trans_z(data);
	data->prints.x = data->news.x * data->vector->scale + data->vector->ax;
	data->prints.y = data->news.y * data->vector->scale + data->vector->ay;
}
