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
	bres_x(data);
	bres_y(data);
}

void	render(t_data *data)
{
	clear_image(data);
	my_image(data);
	mlx_put_image_to_window(data->screen->mlx, data->screen->win,
		data->screen->img, 0, 0);
}
