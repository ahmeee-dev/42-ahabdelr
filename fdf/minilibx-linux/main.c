#include "mlx.h"
#include "mlx_int.h"

#define WIN_HEIGHT 500
#define WIN_LENGHT 700
typedef struct	s_data {
	void	*img;
	void	*addr;
	int	bpp;
	int	line_len;
	int	endian;
	int	px;
	int	py;
	void	*window;
	void	*mlx;
}			t_data;

int	compreso(int num, int bord)
{
	if (num >= -bord && num <= bord)
		return 1;
	return 0;
}

void	draw(t_data *img)
{
	char	*pixel;
	int	color = 0xFF0000;

	for (int y = 0; y < WIN_HEIGHT; y++)
	{
		for (int x = 0; x < WIN_LENGHT; x++)
		{
			pixel = img->addr + y * img->line_len + x * (img->bpp / 8);
			if (!(x % 50) || !(y % 50))
				*(unsigned int *)pixel = color;

		}
	}

}

void	ft_free(t_data *img_struct)
{
	mlx_destroy_image(img_struct->mlx, img_struct->img);
	mlx_destroy_window(img_struct->mlx, img_struct->window);
	mlx_destroy_display(img_struct->mlx);
	free(img_struct->mlx);
}

int	uscita(int key, t_data *img_struct)
{
	int	raggio = 25;

	if (key == 65307)
	{
		ft_free(img_struct);
		exit(0);
	}
	else if (key == 65362 && img_struct->py > 0)
		img_struct->py-= raggio * 2;
	else if (key == 65364 && img_struct->py < WIN_HEIGHT - raggio * 2)
		img_struct->py+= raggio * 2;
	else if (key == 65363 && img_struct->px < WIN_LENGHT - raggio * 2)
		img_struct->px+= raggio * 2;
	else if (key == 65361 && img_struct->px > 0)
		img_struct->px-= raggio * 2;
}

int	render(int key, t_data *img_struct)
{
	uscita(key, img_struct);
	draw(img_struct);
	mlx_put_image_to_window(img_struct->mlx, img_struct->window, img_struct->img, 0, 0);
}

int main()
{
	t_data	img_struct;

	img_struct.px = 0;
	img_struct.py = 0;
	img_struct.mlx = mlx_init();
	img_struct.window = mlx_new_window(img_struct.mlx, WIN_LENGHT, WIN_HEIGHT, "vamos");
	mlx_do_key_autorepeaton(img_struct.mlx);
	img_struct.img = mlx_new_image(img_struct.mlx, WIN_LENGHT, WIN_HEIGHT);
	img_struct.addr = mlx_get_data_addr(img_struct.img, &img_struct.bpp, &img_struct.line_len, &img_struct.endian);
	draw(&img_struct);
	mlx_put_image_to_window(img_struct.mlx, img_struct.window, img_struct.img, 0, 0);
	mlx_hook(img_struct.window, 02, 1L<<0, render, &img_struct);
	mlx_loop(img_struct.mlx);

	ft_free(&img_struct);
}

	// int	raggio = 25;
	// int	color = 0xFF0000;
	// int	xc = raggio;
	// int	yc = raggio;
	// char	*player;
	// for (int y = 0; y <= raggio * 2; y++)
	// {
	// 	for (int x = 0; x <= raggio * 2; x++)
	// 	{
	// 		for (int off_y = 0; y + off_y <= WIN_HEIGHT; off_y += raggio * 2)
	// 		{
	// 			for (int off_x = 0; x + off_x <= WIN_LENGHT; off_x += raggio * 2)
	// 			{
	// 				pixel = img->addr + (y + off_y) * img->line_len + (x + off_x) * (img->bpp / 8);
	// 				if (compreso((x - xc) * (x - xc) + (y - yc) * (y - yc), raggio * raggio))
	// 					*(unsigned int *)pixel = color;
	// 			}
	// 		}
	// 	}
	// }
	// for (int posy = 0; posy <= raggio * 2; posy++)
	// {
	// 	for (int posx = 0; posx <= raggio * 2; posx++)
	// 	{
	// 		player = img->addr + (img->py + posy) * img->line_len + (img->px + posx) * (img->bpp / 8);
	// 		if (img->py + posy <= WIN_HEIGHT && img->px + posx <= WIN_LENGHT)
	// 			*(unsigned int *)player = 0x000FF0;
	// 	}
	// }