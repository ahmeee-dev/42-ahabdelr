/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:57:52 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/05 13:13:28 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "stdio.h"
#include <math.h>

float	rad(int degrees)
{
	float	rad;

	rad = degrees * PI / 180;
	return (rad);
}

void	x_rotation(t_data *data, int sign)
{
	int	size;

	size = 5;
	if (sign < 0)
		size *= -1;
	data->vector->tx += size;
}

void	y_rotation(t_data *data, int sign)
{
	int	size;

	size = 5;
	if (sign < 0)
		size *= -1;
	data->vector->ty += size;
}

void	z_rotation(t_data *data, int sign)
{
	int	size;

	size = 5;
	if (sign < 0)
		size *= -1;
	data->vector->tz += size;
}
