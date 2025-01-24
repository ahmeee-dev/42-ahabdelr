/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:33:35 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/24 18:31:47 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stdio.h"
#include "fdf.h"
#include "minilibx-linux/mlx.h"
#include <math.h>

void	up_scale(t_data *data)
{
	data->vector->tx *= 1.1;
	data->vector->ty *= 1.1;
	data->vector->tz *= 1.1;
	render(data);
}

void	down_scale(t_data *data)
{
	data->vector->tx *= 0.9;
	data->vector->ty *= 0.9;
	data->vector->tz *= 0.9;
	render(data);
}
