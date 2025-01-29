/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_gestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:30:09 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/27 09:42:25 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>

void	screen_init(t_screen *screen)
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "FdF");
	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
}

void	start(t_data *data)
{
	data->vector->tx = 30;
	data->vector->ty = 45;
	data->vector->tz = 0;
	data->vector->ay = HEIGHT / 2 - 300 - data->map->map_y / 2;
	data->vector->ax = WIDTH / 2 - data->map->map_x / 2;
	data->vector->scale = (HEIGHT / (data->map->map_y) + WIDTH
			/ data->map->map_x) * 1 / 6;
}
