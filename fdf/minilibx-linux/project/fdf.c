/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:56:04 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/05 14:25:53 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "stdio.h"

t_coordinates	*parse_map(t_map *map, char *arg)
{
	t_coordinates	*matrix;

	map->file = arg;
	map_size(map);
	matrix = (t_coordinates *)malloc(sizeof(t_coordinates) * (map->map_y
				* map->map_x));
	if (matrix == NULL)
		return (NULL);
	matrix_population(&matrix, map);
	return (matrix);
}

int	main(int argc, char **argv)
{
	t_map			map;
	t_coordinates	*matrix;
	t_screen		screen;
	t_data			data;
	t_vector		vector;

	if (argc != 2)
	{
		ft_printf("Error: Wrong number of parameter");
		exit(0);
	}
	map.file = argv[1];
	matrix = parse_map(&map, argv[1]);
	screen_init(&screen);
	node_init(&data, &matrix, &vector, &screen);
	mlx_do_key_autorepeaton(screen.mlx);
	data.map = &map;
	start(&data);
	screen.addr = mlx_get_data_addr(screen.img, &screen.bpp, &screen.size_line,
			&screen.endian);
	render(&data);
	mlx_hook(screen.win, 2, 1L << 0, key_knot, &data);
	mlx_hook(screen.win, 17, 0, fdf_free, &data);
	mlx_loop(data.screen->mlx);
	return (0);
}
