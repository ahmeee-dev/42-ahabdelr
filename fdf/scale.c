/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:33:35 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/05 15:46:14 by marvin@42.f      ###   ########.fr       */
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
	if (data->vector->scale >= 2)
		data->vector->scale -= 2;
}

void	z_up_down(t_data *data, float num)
{
	data->vector->trans_z += num;
}
