/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_population.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:18 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/22 15:14:59 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <unistd.h>

void	matrix_population(t_coordinates **matrix, t_map *map)
{
	int	i;
	
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		matrix[i]->x = i % map->map_x;
		matrix[i]->y = i / map->map_x;
		matrix[i]->z = 0;
		i++;
	}
}