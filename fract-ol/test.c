#include <mlx.h>
#include <math.h>
#include <stdio.h>
#define EVENT_KEY	114
#define WIDTH		1000
#define HEIGHT		1000
#define ESCAPE_RADIUS	2
#define MAX_ITERATION	1000
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
	t_complex	c;
	t_data		data;
}		t_vars;

int	is_in_julia_set(int i, int j)
{
	t_complex	z;
	int		r_squared;
	int		iteration;
	double		temp;

	z.re = (j - WIDTH / 2.0) * (ESCAPE_RADIUS + ESCAPE_RADIUS) / HEIGHT;
	z.im = (HEIGHT / 2.0 - i) * (ESCAPE_RADIUS + ESCAPE_RADIUS) / HEIGHT;
	r_squared = pow(ESCAPE_RADIUS, 2);
	iteration = -1;
	while (pow(z.re, 2) + pow(z.im, 2) < r_squared && ++iteration < MAX_ITERATION)
	{
		temp = z.re;
		z.re = pow(z.re, 2) - pow(z.im, 2) + C_RE;
		z.im = 2 * temp * z.im + C_IM;
	}
	return (iteration == MAX_ITERATION);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_pressed(int keycode, t_vars *vars)
{
	int	i;
	int	j;
	int	color;

	if (keycode != EVENT_KEY)
		return (0);
	color = 0xFFFFFF00;
	i = -1;
	while (i++ < HEIGHT)
	{
		j = -1;
		while (j++ < WIDTH)
			if (is_in_julia_set(i, j))
				my_mlx_pixel_put(&vars->data, i, j, color);
		color += 0x00000001;
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
