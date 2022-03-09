#include <mlx.h>
#include <math.h>
#include <stdio.h>
#define EVENT_KEY	114
#define WIDTH		800
#define HEIGHT		600
#define ESCAPE_RADIUS	2.0
#define MAX_ITERATION	256
#define C_RE		(double)-0.4
#define C_IM		(double)0.6

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

int	is_in_julia_set(int x, int y)
{
	t_complex	z;
	int		r_squared;
	int		iteration;
	int		size;
	double		temp;

	size = WIDTH;
	if (HEIGHT < WIDTH)
		size = HEIGHT;
	z.re = (x - WIDTH / 2) * (ESCAPE_RADIUS + ESCAPE_RADIUS) / size;
	z.im = (HEIGHT / 2 - y) * (ESCAPE_RADIUS + ESCAPE_RADIUS) / size;
	r_squared = pow(ESCAPE_RADIUS, 2);
	iteration = 0;
	while (pow(z.re, 2) + pow(z.im, 2) < r_squared && ++iteration <= MAX_ITERATION)
	{
		temp = z.re;
		z.re = pow(z.re, 2) - pow(z.im, 2) + C_RE;
		z.im = 2 * temp * z.im + C_IM;
	}
	return (iteration);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_pressed(int keycode, t_vars *vars)
{
	int	x_idx;
	int	y_idx;
	int	color;

	if (keycode != EVENT_KEY)
		return (0);
	x_idx = -1;
	while (x_idx++ < WIDTH)
	{
		y_idx = -1;
		while (y_idx++ < HEIGHT)
		{
			color = is_in_julia_set(x_idx, y_idx);
			if (color < MAX_ITERATION)
				my_mlx_pixel_put(&(vars->data), x_idx, y_idx, color);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");
	vars.data.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits_per_pixel, &vars.data.line_length, &vars.data.endian);
	mlx_hook(vars.win, 2, 1L<<0, key_pressed, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
