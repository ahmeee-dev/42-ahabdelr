/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traslation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:48:41 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/24 17:30:25 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stdio.h"
#include "fdf.h"
#include "minilibx-linux/mlx.h"
#include <math.h>

void	traslation(t_data *data, int dir)
{
	int	size;

	size = 5;
	if (dir == 1)
		data->vector->ax += size;
	else if (dir == 2)
		data->vector->ay += size;
	else if (dir == -1)
		data->vector->ax -= size;
	else if (dir == -2)
		data->vector->ay -= size;
}
