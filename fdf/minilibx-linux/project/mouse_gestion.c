/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:57:19 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/25 07:36:41 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stdio.h"
#include "fdf.h"
#include "minilibx-linux/mlx.h"

int	mouse_move(int x, int y, void *param)
{
	int	dx;
	int	dy;
	t_data	*data;

	ft_printf("ok");
	data = (t_data *)param;
	if (data->screen->press == 1)
	{
		dx = x - data->screen->prev_x;
		dy = y - data->screen->prev_y;
		data->vector->ax += dx;
		data->vector->ay += dy;
		data->screen->prev_x = x;
		data->screen->prev_y = y;
		render(data);
	}
	return (0);
}

int	mouse(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	t_data	*data;

		ft_printf("ok1");
	data = (t_data *)param;
	if (button == 1)
	{
		data->screen->press = 1;
		render(data);
	}
	if (button == 4)
	{
		up_scale(data);
		render(data);
	}
	else if (button == 5)
	{
		down_scale(data);
		render(data);
	}
	return (0);
}

int	mouse_release(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	t_data	*data;

	data = (t_data *)param;
	if (button == 1)
		data->screen->press = 0;
	return (0);
}