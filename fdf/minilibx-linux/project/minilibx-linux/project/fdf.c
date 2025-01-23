/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:56:04 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/23 15:32:02 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stdio.h"
#include "fdf.h"

//aggiungere free ad ogni get_next_line per evitare leaks
//gestire i leaks legati alla strjoin di map->file
//la mappa va inserita senza appendice di formato

void	fdf(int argc, char **argv)
{
	t_map		map;
	t_coordinates	*matrix;
	t_screen	screen;

	map.file = argv[1];
	matrix = get_eminem(&map, argv[1]);
}

t_coordinates	*get_eminem(t_map *map, char *arg)
{
	t_coordinates	*matrix;

	map->file = arg;
	map_size(&map);
	matrix = (t_coordinates *)malloc(sizeof(t_coordinates) * (map->map_y * map->map_x));
	matrix_population(&matrix, map);
	return (matrix);
}