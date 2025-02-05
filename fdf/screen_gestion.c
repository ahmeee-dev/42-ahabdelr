/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_gestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:30:09 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/05 14:57:09 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	screen_init(t_screen *screen)
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "FdF");
	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
}

void	start(t_data *data)
{
	data->vector->tx = 35;
	data->vector->ty = -15;
	data->vector->tz = 0;
	data->vector->trans_z = 0;
	data->vector->scale = (HEIGHT / (data->map->map_y) + WIDTH
			/ data->map->map_x) * 1 / 4;
	data->vector->ay = HEIGHT / 2 - (data->map->map_y / 2
			* data->vector->scale);
	data->vector->ax = WIDTH / 2 - (data->map->map_x / 2 * data->vector->scale);
	data->vector->proj = 1;
}

void	random_position(t_data *data)
{
	data->vector->tx = rand();
	data->vector->ty = rand();
	data->vector->tz = rand();
	data->vector->ay = rand() % HEIGHT;
	data->vector->ax = rand() % WIDTH;
}
