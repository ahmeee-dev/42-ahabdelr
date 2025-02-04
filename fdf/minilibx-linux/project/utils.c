/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:23:13 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/25 14:35:33 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>

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

void	bres_select(t_data *data, t_coordinates old, t_coordinates new, int i)
{
	if (abs((int)new.x - (int)old.x) > abs((int)new.y - (int)old.y))
		col_lines(data, old, new, i);
	else
		row_lines(data, old, new, i);
}

int	fdf_free(t_data *data)
{
	mlx_destroy_image(data->screen->mlx, data->screen->img);
	mlx_destroy_window(data->screen->mlx, data->screen->win);
	mlx_destroy_display(data->screen->mlx);
	free(data->screen->mlx);
	free(data->matrix);
	free(data->map->file);
	return (0);
}