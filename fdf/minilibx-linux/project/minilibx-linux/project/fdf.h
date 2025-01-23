/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:37:15 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/23 15:31:39 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define HEIGHT 450
# define WIDTH 720

void map_size(t_map *map);
void	matrix_population(t_coordinates **matrix, t_map *map);

typedef struct	s_map
{
	char	*file;
	int	fd;
	int	map_y;
	int	map_x;
	char	**map_row;
}		t_map;

typedef struct s_coordinates
{
	int	x;
	int	y;
	double	z;
}		t_coordinates;

typedef struct s_vector
{
	double	tx;
	double	ty;
	double	tz;
}		t_vector;

typedef struct	s_screen
{
	void	*mlx;
	void	*win;
	void	*img;
}		t_screen;