/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:06:26 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/25 16:32:10 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include "minilibx-linux/mlx.h"

void	my_image(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	trans_x;
	int	trans_y;	

	// for (int yy = 0; yy < HEIGHT; yy++)
	// {
	// 	for (int xx = 0; xx < WIDTH; xx++)
	// 	{
	// 		data->screen->position = (data->screen->addr + yy * (data->screen->size_line) + xx * (data->screen->bpp / 8));
	// 		*(unsigned int*)(data->screen->position) = 0xFF0000;
	// 	}
	// }
	// mlx_put_image_to_window(data->screen->mlx, data->screen->win, data->screen->img, 0, 0);
	// ft_printf("ok");
	y = 0;
	while (y < data->map->map_y)
	{
		x = 0;
		while (x < data->map->map_x)
		{
			i = y * data->map->map_x + x;
			trans_x = (data->matrix[i].x * data->vector->tx) + data->vector->ax;
			trans_y = (data->matrix[i].y * data->vector->ty) + data->vector->ay;
			if ((trans_x >= 0 && trans_x < WIDTH) && (trans_y >= 0 && trans_y < HEIGHT))
			{
				data->screen->position = (data->screen->addr + trans_x * (data->screen->size_line) + trans_y * (data->screen->bpp / 8));
				//l'errore nasce quando provo ad accedere a questa memoria
				//*(unsigned int*)(data->screen->position) = 0x00FF00;
				ft_printf("%d --- %d\n", x, y);
			}
			x++;
		}
		y++;
	}
}

void	render(t_data *data)
{
	my_image(data);
	mlx_put_image_to_window(data->screen->mlx, data->screen->win, data->screen->img, 0, 0);
}