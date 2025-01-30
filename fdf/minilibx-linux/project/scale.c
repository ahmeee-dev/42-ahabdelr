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

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "stdio.h"
#include <math.h>

void	up_scale(t_data *data)
{
	if (data->vector->scale < 150)
		data->vector->scale += 2;
}

void	down_scale(t_data *data)
{
	if (data->vector->scale >= 6)
		data->vector->scale -= 2;
}

void	z_up_down(t_data *data, int num)
{
	data->vector->trans_z += num;
}
