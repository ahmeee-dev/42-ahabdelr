#include "fdf.h"
#include "libft/libft.h"
#include <math.h>
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>

void    bres_put(t_data *data, float x, float y)
{
	if ((x >= 0 && x < WIDTH) && (y >= 0
			&& y < HEIGHT))
	{
		    data->screen->position = (data->screen->addr + (int)y
		    		* (data->screen->size_line) + (int)x * (data->screen->bpp
		    			/ 8));
		    *(unsigned int *)(data->screen->position) = 0x0000FF;
    }
}

void    col_lines(t_data *data, t_coordinates old, t_coordinates new)
{
    int dx;
    int dy;
    int dir;
    int p;
    
    old.z = 0;
    swap(&old, &new, 'x');
    dx = new.x - old.x;
    dy = new.y - old.y;
    dir = -1 * (dy < 0) + 1 * (dy >= 0);
    dy *= dir;
    if (dx != 0)
    {
        p = 2 * dy - dx;
        while (old.z++ < dx + 1)
        {
            bres_put(data, old.x + old.z, old.y);
            if (p >= 0)
            {
                old.y += dir;
                p = p - 2 * dx;
            }
            p = p + 2 * dy;
        }
    }
}

void    row_lines(t_data *data, t_coordinates old, t_coordinates new)
{
    int dx;
    int dy;
    int dir;
    int p;

    old.z = 0;
    swap(&old, &new, 'y');
    dx = new.x - old.x;
    dy = new.y - old.y;
    dir = -1 * (dx < 0) + 1 * (dx >= 0);
    dx *= dir;
    if (dy != 0)
    {
        p = 2*dx - dy;
        while (old.z++ < dy + 1)
        {
            bres_put(data, old.x, old.y + old.z);
            if (p >= 0)
            {
                old.x += dir;
                p = p - 2 * dy;
            }
            p = p + 2 * dx;
        }
    }
}

void	bres_x(t_data *data)
{
	int	i;
	int	x;
	int	y;
	t_coordinates curr;
	t_coordinates	old;
	
	y = 0;
	i = 0;
	while (y < data->map->map_y)
	{
		x = 1;
		while (x < data->map->map_x)
		{
			i = y * data->map->map_x + x;
			rotate(data, i);
			curr = data->prints;
			rotate(data, i - 1);
			old = data->prints;
			bres_select(data, old, curr);
			x++;
		}
		y++;
	}
}

void	bres_y(t_data *data)
{
	int	i;
	int	x;
	int	y;
	t_coordinates curr;
	t_coordinates	old;
	
	x = 0;
	i = 0;
	while (x < data->map->map_x)
	{
		y = 1;
		while (y < data->map->map_y)
		{
			i = y * data->map->map_x + x;
			rotate(data, i);
			curr = data->prints;
			rotate(data, i - data->map->map_x);
			old = data->prints;
			bres_select(data, old, curr);
			y++;
		}
		x++;
	}
}