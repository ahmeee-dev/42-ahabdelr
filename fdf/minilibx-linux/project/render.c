/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:06:26 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/05 13:37:25 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

void	clear_image(t_data *data)
{
	int		x;
	int		y;

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
	bres_x(data);
	bres_y(data);
	mlx_put_image_to_window(data->screen->mlx, data->screen->win,
		data->screen->img, 0, 0);
}
