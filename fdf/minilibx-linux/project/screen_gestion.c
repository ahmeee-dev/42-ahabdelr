/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_gestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:30:09 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/27 09:42:25 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include "minilibx-linux/mlx.h"

void	screen_init(t_screen *screen)
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "FdF");
	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
}

// void	screen_init(t_screen *screen)
// {
// 	screen->mlx = mlx_init();
// 	if (!screen->mlx)
// 	{
// 		ft_printf("Errore: Impossibile inizializzare mlx\n");
// 		exit(1);
// 	}
// 	screen->win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "FdF");
// 	if (!screen->win)
// 	{
// 		ft_printf("Errore: Impossibile creare una finestra\n");
// 		exit(1);
// 	}
// 	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
// 	if (!screen->img)
// 	{
// 		ft_printf("Errore: Impossibile creare un'immagine\n");
// 		exit(1);
// 	}

// 	// Ottenere l'indirizzo del buffer immagine
// 	screen->addr = mlx_get_data_addr(screen->img, &screen->bpp, &screen->size_line, &screen->endian);
// 	if (!screen->addr)
// 	{
// 		ft_printf("Errore: Impossibile ottenere l'indirizzo del buffer immagine\n");
// 		exit(1);
// 	}

// 	// Stampa di debug per verificare
// 	ft_printf("bpp: %d, size_line: %d, endian: %d\n", screen->bpp, screen->size_line, screen->endian);
// }


void	start(t_data *data)
{
	data->vector->tx = 2.8284;
	data->vector->ty = 1.3178;
	data->vector->tz = 1;
	data->vector->ax = WIDTH/2 - data->map->map_x / 2;
	data->vector->ay = HEIGHT/2 - data->map->map_y / 2;
}