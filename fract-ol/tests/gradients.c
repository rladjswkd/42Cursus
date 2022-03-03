#include <mlx.h>

typedef struct	s_data
{
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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 0xFF, 0xFF, "Hello world!");
	img.img = mlx_new_image(mlx, 0xFF, 0xFF);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	j = 0;
	while (j++ < 0xFF)
	{
		i = 0;
		while (i++ < 0xFF)
			my_mlx_pixel_put(&img, i, j, i << 24 | i << 16 | i << 8 | i);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
