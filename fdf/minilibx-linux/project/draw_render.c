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


void	draw_proj(t_data *data)
{
	int	px;
	int	py;
	int	pz;
	int	i;

	i = 0;
	while (i < data->map->map_x * data->map->map_y)
	{
		py = data->map->map_y - data->matrix[i].y;
		px = (data->matrix[i].x) / py * 100;
		pz = data->matrix[i].z / py * 100;
		if (((px > 0 && px < WIDTH) && (pz > 0 && pz < HEIGHT)))
		{
			data->screen->position = (data->screen->addr + (int)pz * (data->screen->size_line) + (int)px * (data->screen->bpp / 8));
			*(unsigned int *)(data->screen->position) = 0xFFFFFFFF; 
		}
		i++;
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

void	render(t_data *data)
{
	clear_image(data);
	if (data->vector->proj == 1)
	{
		bres_x(data);
		bres_y(data);
	}
	else 
		draw_proj(data);
		mlx_put_image_to_window(data->screen->mlx, data->screen->win,
		data->screen->img, 0, 0);
}
