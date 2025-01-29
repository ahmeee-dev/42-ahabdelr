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