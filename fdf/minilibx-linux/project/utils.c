/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:23:13 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/05 14:13:27 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>

void	print_vars(t_data *data)
{
        
	ft_printf("____________________VALUES___________________________\n\n\n");
    ft_printf("Map:\t\t\t\"%s\"\n\n", data->map->file);
	ft_printf("X axis rotation:\t [%i]\nY axis rotation:\t [%i]\n",
		data->vector->tx, data->vector->ty);
	ft_printf("z axis rotation:\t [%i]\n\n", data->vector->tz);
	ft_printf("Scale:\t\t\t [%i]\n\n", data->vector->scale);
	ft_printf("Translation on X:\t [%i]\nTranslation on Y:\t [%i]\n\n",
		data->vector->ax, data->vector->ay);
	ft_printf("Image Width:\t\t [%i]\n", data->map->map_x);
	ft_printf("Image Height:\t\t [%i]\n\n", data->map->map_y);
	ft_printf("Z Transformation: \t [%i]\n\n", data->vector->trans_z);
	ft_printf("______________________________________________________\n\n");
}

void	my_pixel(t_data *data, float x, float y, int i)
{
	unsigned int	new_color;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		data->screen->position = (data->screen->addr + (int)y
				* (data->screen->size_line) + (int)x * (data->screen->bpp / 8));
		if (data->matrix[i].z == 0)
			new_color = 0xFFFFFFFF;
		else if (data->matrix[i].z > 0)
			new_color = 0xAA9e1212;
		else
			new_color = 0xAA485990;
		*(unsigned int *)(data->screen->position) = new_color;
	}
}

void	node_init(t_data *data, t_coordinates **matrix, t_vector *vector,
		t_screen *screen)
{
	data->matrix = (*matrix);
	data->screen = screen;
	data->screen->prev_x = 0;
	data->screen->prev_y = 0;
	data->vector = vector;
}

void	swap(t_coordinates *old, t_coordinates *new, int let)
{
	t_coordinates	temp;

	if ((let == 'x' && old->x > new->x) || (let == 'y' && old->y > new->y))
	{
		temp.x = old->x;
		temp.y = old->y;
		old->x = new->x;
		old->y = new->y;
		new->x = temp.x;
		new->y = temp.y;
	}
}

int	fdf_free(t_data *data)
{
	mlx_destroy_image(data->screen->mlx, data->screen->img);
	mlx_destroy_window(data->screen->mlx, data->screen->win);
	mlx_destroy_display(data->screen->mlx);
	free(data->screen->mlx);
	free(data->matrix);
	exit(0);
	return (0);
}
