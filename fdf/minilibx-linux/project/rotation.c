/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:57:52 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/24 18:06:33 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stdio.h"
#include "fdf.h"
#include "minilibx-linux/mlx.h"
#include <math.h>

float	rad(int	degrees)
{
	float	rad;

	rad = degrees * PI / 180;
	return (rad);
}

// void	x_rotation(t_data *data, int sign)
// {
// 	float	temp_y;
// 	float	temp_z;
// 	int	size;

// 	size = 5;
// 	if (sign < 0)
// 		size *= -1;
// 	temp_y = data->vector->ty;
// 	temp_z = data->vector->tz;
// 	data->vector->ty = temp_y * cos(rad(size)) - temp_z * sin(rad(size));
// 	data->vector->tz = temp_y * sin(rad(size)) + temp_z * cos(rad(size));
// }

void	x_rotation(t_data *data, int sign)
{
	int	size;

	size = 5;
	if (sign < 0)
		size *= -1;
	data->vector->tx += size;
}

// void	y_rotation(t_data *data, int sign)
// {
// 	float	temp_x;
// 	float	temp_z;
// 	int	size;

// 	size = 5;
// 	if (sign < 0)
// 		size *= -1;
// 	temp_x = data->vector->tx;
// 	temp_z = data->vector->tz;
// 	data->vector->tx = temp_x * cos(rad(size)) + temp_z * sin(rad(size));
// 	data->vector->tz = -temp_x * sin(rad(size)) + temp_z * cos(rad(size));
// }

void	y_rotation(t_data *data, int sign)
{
	int	size;

	size = 5;
	if (sign < 0)
		size *= -1;
	data->vector->ty += size;
}

// void	z_rotation(t_data *data, int sign)
// {
// 	float	temp_y;
// 	float	temp_x;
// 	int	size;

// 	size = 5;
// 	if (sign < 0)
// 		size *= -1;
// 	temp_y = data->vector->ty;
// 	temp_x = data->vector->tx;
// 	data->vector->tx = temp_x * cos(rad(size)) - temp_y * sin(rad(size));
// 	data->vector->ty = temp_x * sin(rad(size)) + temp_y * cos(rad(size));
// }

void	z_rotation(t_data *data, int sign)
{
	int	size;

	size = 5;
	if (sign < 0)
		size *= -1;
	data->vector->tz += size;
}