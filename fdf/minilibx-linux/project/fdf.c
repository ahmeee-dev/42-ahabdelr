/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:56:04 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/25 18:20:42 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stdio.h"
#include "fdf.h"
#include "minilibx-linux/mlx.h"

t_coordinates	*parse_map(t_map *map, char *arg)
{
	t_coordinates	*matrix;

	map->file = arg;
	map_size(map);
	matrix = (t_coordinates *)malloc(sizeof(t_coordinates) * (map->map_y * map->map_x));
	if (matrix == NULL)
		return NULL;
	matrix_population(&matrix, map);
	return (matrix);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_coordinates	*matrix;
	t_screen	screen;
	t_data		data;
	t_vector	vector;

	if (argc != 2)
		exit(0);
	map.file = argv[1];
	matrix = parse_map(&map, argv[1]);
	screen_init(&screen);
	node_init(&data, &matrix, &vector, &screen);
	mlx_do_key_autorepeaton(screen.mlx);
	data.map = &map;
	start(&data);
	screen.addr = mlx_get_data_addr(screen.img, &screen.bpp, &screen.size_line, &screen.endian);
	render(&data);
	mlx_hook(screen.win, 2, 1L << 0, keypress, &data);
	mlx_loop(data.screen->mlx);
	return (0);
}
