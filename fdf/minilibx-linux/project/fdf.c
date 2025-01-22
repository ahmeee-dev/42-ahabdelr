/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:56:04 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/22 14:53:07 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stdio.h"
#include "fdf.h"

void	fdf(int argc, char **argv)
{
	t_map		map;
	t_coordinates	*matrix;

	map_size(&map, argv[1]);
	matrix = (t_coordinates *)malloc(sizeof(t_coordinates) * (map.map_y * map.map_x));

}