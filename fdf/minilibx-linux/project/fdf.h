/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:37:15 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/22 13:33:24 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define HEIGHT 450
# define WIDTH 720

void map_size(char *file, t_map *map);

typedef struct	s_map
{
	int	map_y;
	int	map_x;
	char	**map_row;
}		t_map;

typedef struct s_coordinates
{
	int	x;
	int	y;
	int	z;
}		t_coordinates;
