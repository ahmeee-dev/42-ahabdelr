/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:05:14 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/05 15:12:18 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "stdio.h"

void	keypress_para(int key, t_data *data)
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
		x_rotation_para(data, 1);
	else if (key == 's')
		x_rotation_para(data, -1);
	else if (key == 'a')
		y_rotation_para(data, -1);
	else if (key == 'd')
		y_rotation_para(data, 1);
	else if (key == 'z')
		z_rotation_para(data, 1);
	else if (key == 'm')
		z_rotation_para(data, -1);
	else if (key == 'r')
		z_rotation_para(data, 0);
	else if (key == 'l')
		random_position(data);
}

void	keypress(int key, t_data *data)
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
	else if (key == 'r')
		start(data);
}

int	key_knot(int key, t_data *data)
{
	if (key == 'p')
		data->vector->proj = 2;
	else if (key == 'o')
		data->vector->proj = 1;
	else if (key == 65307)
		fdf_free(data);
	else if (key == 'j')
		up_scale(data);
	else if (key == 'k')
		down_scale(data);
	else if (key == 'q')
		print_vars(data);
	else if (key == '8')
		z_up_down(data, 1);
	else if (key == '9')
		z_up_down(data, -1);
	if (data->vector->proj == 1)
		(keypress(key, data));
	else
		keypress_para(key, data);
	render(data);
	return (0);
}
