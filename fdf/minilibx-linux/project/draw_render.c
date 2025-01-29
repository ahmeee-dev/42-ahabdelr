/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:06:26 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/27 09:42:58 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <math.h>
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>

void	my_pixel(t_data *data, t_coordinates prints, int i)
{
	if ((prints.x >= 0 && prints.x < WIDTH) && (prints.y >= 0
			&& prints.y < HEIGHT))
	{
		data->screen->position = (data->screen->addr + (int)prints.y
				* (data->screen->size_line) + (int)prints.x * (data->screen->bpp
					/ 8));
		*(unsigned int *)(data->screen->position) = 0xFF0000;
		if (data->matrix[i].z != 0)
			*(unsigned int *)(data->screen->position) = 0x00FF00;
	}
}

void	clear_image(t_data *data)
{
	int		x;
	int		y;
	char	*pixel;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->screen->position = data->screen->addr + (y
					* data->screen->size_line) + x * (data->screen->bpp / 8);
			*(unsigned int *)data->screen->position = 0x000000;
			x++;
		}
		y++;
	}
}

void	my_image(t_data *data)
{
	int				x;
	int				y;
	int				i;
	t_coordinates	prints;

	y = 0;
	while (y < data->map->map_y)
	{
		x = 0;
		while (x < data->map->map_x)
		{
			i = y * data->map->map_x + x;
			rotate(data, i);
			prints.x = data->news.x * data->vector->scale + data->vector->ax;
			prints.y = data->news.y * data->vector->scale + data->vector->ay;
			my_pixel(data, prints, i);
			x++;
		}
		y++;
	}
}

void	render(t_data *data)
{
	clear_image(data);
	my_image(data);
	mlx_put_image_to_window(data->screen->mlx, data->screen->win,
		data->screen->img, 0, 0);
}
