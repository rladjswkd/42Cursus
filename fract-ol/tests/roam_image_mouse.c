#include <mlx.h>
#include <stdio.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	t_data	data;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_mouse(int x, int y, t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int	img_width;
	int	img_height;
	char	*relative_path = "./teapot.xpm";
	int	i;
	int	j;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "roam image - mouse");
	vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	vars.data.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits_per_pixel, &vars.data.line_length, &vars.data.endian);
	i = -1;
	while (i++ <= 1920)
	{
		j = -1;
		while (j++ <= 1080)
			my_mlx_pixel_put(&vars.data, i, j, 0x00000000);
	}
	mlx_hook(vars.win, 6, 1L<<6, handle_mouse, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
