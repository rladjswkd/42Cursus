#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#define RADIUS 8
#define W 119
#define A 97
#define S 115
#define D 100

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	int	x;
	int	y;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render_next_frame(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (i++ < 0xFF)
	{
		j = -1;
		while (j++ < 0xFF)
		{
			if ((data->x - i) * (data->x - i) + (data->y - j) * (data-> y - j) <= RADIUS * RADIUS)
				my_mlx_pixel_put(data, i, j, 0x000000FF);
			else
				my_mlx_pixel_put(data, i, j, 0xFFFFFFFF);
		}

	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	move_wasd(int keycode, t_data *data)
{
	if (keycode == W && data->y - RADIUS > 5)
		data->y -= 5;
	else if (keycode == A && data->x - RADIUS > 5)
		data->x -= 5;
	else if (keycode == S && data->y + RADIUS < 0xFF - 5)
		data->y += 5;
	else if (keycode == D && data->x + RADIUS < 0xFF - 5)
		data->x += 5;	
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 0xFF, 0xFF, "Hello world!");
	data.img = mlx_new_image(data.mlx, 0xFF, 0xFF);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	data.x = 0xF0;
	data.y = 0xF0;
	mlx_hook(data.win, 2, 1L<<0, move_wasd, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
