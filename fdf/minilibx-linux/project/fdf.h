/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:37:15 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/25 15:30:36 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define HEIGHT 800
# define WIDTH 1280
# define PI 3.1415926

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
	int	ax;
	int	ay;
}		t_vector;

typedef struct	s_screen
{
	//riordina le variabili nella struct
	int	press;
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int	bpp;
	int	endian;
	int	size_line;
	char	*position;
	int	prev_x;
	int	prev_y;
}		t_screen;

typedef struct	s_data
{
	t_coordinates	*matrix;
	t_vector	*vector;
	t_screen	*screen;
	t_map		*map;
}		t_data;

//screen - map
void	map_size(t_map *map);
void	matrix_population(t_coordinates **matrix, t_map *map);
void	screen_init(t_screen *screen);
void	node_init(t_data *data, t_coordinates **matrix, t_vector *vector, t_screen *screen);

//mouse gestion
int	mouse_move(int x, int y, t_data *data);
int	mouse(int button, int x, int y, t_data *data);
int	mouse_release(int button, int x, int y, t_data *data);
int	keypress(int key, t_data *data);

//transformations
void	traslation(t_data *data, int dir);
void	x_rotation(t_data *data, int sign);
void	y_rotation(t_data *data, int sign);
void	z_rotation(t_data *data, int sign);
void	up_scale(t_data *data);
void	down_scale(t_data *data);


//render
void	my_image(t_data *data);
void	render(t_data *data);
void	start(t_data *data);
