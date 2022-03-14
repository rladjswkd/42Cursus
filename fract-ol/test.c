#include <mlx.h>
#include <math.h>
#include <stdio.h>
#define EVENT_KEY	114
#define WIDTH		1000
#define HEIGHT		1000
#define ESCAPE_RADIUS	2
#define MAX_ITERATION	240
#define C_RE		0.285	
#define C_IM		0.01

typedef struct	s_complex
{
	double	re;
	double	im;
}		t_complex;

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
	t_data		data;
}		t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	is_in_julia_set(int x, int y)
{
	t_complex	z;
	int		r_squared;
	int		iter;
	int		size;
	double		temp;
	size = WIDTH;
	if (HEIGHT < WIDTH)
		size = HEIGHT;
	z.re = (x - WIDTH / 2.0) * (ESCAPE_RADIUS + ESCAPE_RADIUS) / size;
	z.im = (HEIGHT / 2.0 - y) * (ESCAPE_RADIUS + ESCAPE_RADIUS) / size;
	r_squared = pow(ESCAPE_RADIUS, 2);
	iter = 0;
	while (pow(z.re, 2) + pow(z.im, 2) <= r_squared && iter++ < MAX_ITERATION)
	{
		temp = z.re;
		z.re = pow(z.re, 2) - pow(z.im, 2) + C_RE;
		z.im = 2 * temp * z.im + C_IM;
	}
	if (iter > MAX_ITERATION)
		return (0);
	else
	{
		iter = (int)((double)iter / MAX_ITERATION * 255.0);
		iter = iter;
		return (iter << 16 | iter << 8 | iter);
	}
}

int	key_pressed(int keycode, t_vars *vars)
{
	int	x_idx;
	int	y_idx;

	if (keycode != EVENT_KEY)
		return (0);
	x_idx = -1;
	while (x_idx++ < WIDTH)
	{
		y_idx = -1;
		while (y_idx++ < HEIGHT)
			my_mlx_pixel_put(&(vars->data), x_idx, y_idx, is_in_julia_set(x_idx, y_idx));
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void)argc;
	(void)argv;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");
	vars.data.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits_per_pixel, &vars.data.line_length, &vars.data.endian);
	mlx_hook(vars.win, 2, 1L<<0, key_pressed, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
