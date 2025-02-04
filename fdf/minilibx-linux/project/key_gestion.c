/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:05:14 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/25 12:25:57 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "stdio.h"

int	keypress(int key, t_data *data)
{
	if (key == 65362)
		traslation(data, -2);
	else if (key == 65364)
		traslation(data, 2);
	else if (key == 65361)
		traslation(data, -1);
	else if (key == 65363)
		traslation(data, 1);
	else if (key == 'w')
		x_rotation(data, 0);
	else if (key == 's')
		x_rotation(data, -1);
	else if (key == 'a')
		y_rotation(data, -1);
	else if (key == 'd')
		y_rotation(data, 0);
	else if (key == 'z')
		z_rotation(data, 0);
	else if (key == 'm')
		z_rotation(data, -1);
	else if (key == 'j')
		up_scale(data);
	else if (key == 'k')
		down_scale(data);
	else if (key == '8')
		z_up_down(data, 1);
	else if (key == '9')
		z_up_down(data, -1);
	else if (key == 65307)
	{
		exit(fdf_free(data));
		return (0);
	}
	else if (key == 'r')
		start(data);
	else if (key == 'p')
		data->vector->proj = 2;
	render(data);
	return (0);
}
