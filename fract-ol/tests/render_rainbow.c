#include <mlx.h>
#include <unistd.h>

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int	count;
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
	static int	rainbow[7] = {0x00FF0000, 0x00FF7F00, 0x00FFFF00, 0x0000FF00, 0x000000FF, 0x004B0082, 0x009400D3};

	i = -1;
	while (i++ < 0xFF)
	{
		j = -1;
		while (j++ < 0xFF)
			my_mlx_pixel_put(data, i, j, rainbow[data->count]);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	data->count = (data->count + 1) % 7;
	usleep(100000);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 0xFF, 0xFF, "Hello world!");
	data.img = mlx_new_image(data.mlx, 0xFF, 0xFF);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	data.count = 0;
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
