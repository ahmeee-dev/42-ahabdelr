/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:56:04 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/24 19:18:02 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stdio.h"
#include "fdf.h"
#include "minilibx-linux/mlx.h"

// gestisci gli errori di malloc 
// gestisci gli errori di allocazione che compie la minilibx
// gestione overflows/underflows -> se arriva in of/uf manda la funzione start e ri-inizializza
// aggiungi la possibilità di aumentare le z con la barra spaziatrice e diminuirle con il delete per fare la bonus 
// l'idea per la bonus è quella di utilizzare funzioni per leggere il file senza doverlo malloccare
// ---evitando tutte le parti che vanno a uccidere 

t_coordinates	*parse_map(t_map *map, char *arg)
{
	t_coordinates	*matrix;

	map->file = arg;
	map_size(&map);
	matrix = (t_coordinates *)malloc(sizeof(t_coordinates) * (map->map_y * map->map_x));
	matrix_population(&matrix, map);
	return (matrix);
}

void	fdf(int argc, char **argv)
{
	t_map		map;
	t_coordinates	*matrix;
	t_screen	screen;
	t_data		data;
	t_vector	vector;

	map.file = argv[1];
	matrix = parse_map(&map, argv[1]);
	screen_init(&screen);
	node_init(&data, &matrix, &vector, &screen);
	data.map = &map;
	mlx_get_data_addr(data.screen->img, data.screen->bpp, data.screen->size_line, data.screen->endian);
	render(&data);
	mlx_hook(screen.mlx, 2, 1L << 0, keypress, &data);
	mlx_hook(screen.mlx, 4, 0, mouse, &data);
	mlx_hook(screen.mlx, 5, 0, mouse_release, &data);
	mlx_hook(screen.mlx, 6, 0, mouse_move, &data);
	mlx_loop(data.screen->mlx);
	
}

/* Da gestire FREE:
	strjoin;
	!!!!!!!vari gnl;!!!!!!!
	mlx pointer
	window
	img pointer
	matrice
*/