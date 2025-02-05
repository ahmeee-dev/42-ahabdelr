/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:04:54 by marvin@42.f       #+#    #+#             */
/*   Updated: 2025/02/05 13:04:55 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "stdio.h"
#include <math.h>

void	x_rotation_para(t_data *data, int sign)
{
	if (data->vector->tx % 90)
		data->vector->tx = 0;
	if (data->vector->ty % 90)
		data->vector->ty = 0;
	if (data->vector->tz % 90)
		data->vector->tz = 0;
	data->vector->tx += (-90) * (sign < 0) + 90 * (sign > 0);
}

void	y_rotation_para(t_data *data, int sign)
{
	if (data->vector->tx % 90)
		data->vector->tx = 0;
	if (data->vector->tz % 90)
		data->vector->tz = 0;
	if (data->vector->ty % 90)
		data->vector->ty = 0;
	data->vector->ty += (-90) * (sign < 0) + 90 * (sign > 0);
}

void	z_rotation_para(t_data *data, int sign)
{
	if (sign == 0)
	{
		data->vector->ty = 0;
		data->vector->tx = 0;
		data->vector->tz = 0;
	}
	if (data->vector->tx % 90)
		data->vector->tx = 0;
	if (data->vector->ty % 90)
		data->vector->ty = 0;
	if (data->vector->tz % 90)
		data->vector->tz = 0;
	data->vector->tz += (-90) * (sign < 0) + 90 * (sign > 0);
}
