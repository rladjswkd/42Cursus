#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#define EVENT_KEY		114//15
#define ESC_KEY			65307//53
#define WIDTH			1000
#define HEIGHT			1000
#define ESCAPE_RADIUS	2
#define MAX_ITERATION	32//256//48//64//100//120
#define C_RE			-0.4//0.45//0//-0.835//-0.70716	
#define C_IM			0.6//0.1428//-0.8//-0.2321//-0.3842

typedef struct	s_complex
{
	double	re;
	double	im;
}		t_complex;

typedef struct	s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_params
{
	int		type;
	int		radius;
	int		max_iter;
	t_complex	julia_c;
}		t_params;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_img		img;
	t_params	params;
}		t_vars;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_len(char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

double	*get_double(char *str, double *val)
{
	double		scale;
       	int		sign;

	sign = 1;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	*val = 0;
	while (47 < *str && *str < 58)
		*val = *val * 10 + sign * (*(str++) - 48);
	if (*str != '.' && *str != '\0')
		return (0);
	str++;
	scale = 10;
	while (47 < *str && *str < 58)
	{
		*val += sign *(*(str++) - 48) / scale;
		scale *= 10;
	}
	if (*str != '\0')
		return (0);
	return (val);
}

int	*get_int(char *str, int *val)
{
	int	sign;

	sign = 1;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	*val = 0;
	while (47 < *str && *str < 58)
		*val = *val * 10 + sign * (*(str++) - 48);
	if (*str != '\0')
		return (0);
	return (val);
}

/*
int	check_julia_set(int x, int y)
{
	t_complex	z;
	int		r_squared;
	int		iter;
	int		size;
	double		temp;
	
	size = width;
	if (height < width)
		size = height;
	z.re = (x - width / 2.0) * (escape_radius + escape_radius) / size;
	z.im = (height / 2.0 - y) * (escape_radius + escape_radius) / size;
	r_squared = escape_radius * escape_radius;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= r_squared && iter++ < max_iteration)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + c_re;
		z.im = 2 * temp * z.im + c_im;
	}
	if (iter > max_iteration)
		return (0);
	else
	{
		iter = (int)((double)iter / max_iteration * 255.0);
		iter = 255 - iter;
		return (iter << 16 | iter << 8 |  iter);
	}
}
*/

int	check_julia_set(int x, int y, t_vars *vars)
{
	t_complex	z;
	int		r_squared;
	int		iter;
	int		size;
	double		temp;
	
	size = WIDTH;
	if (HEIGHT < WIDTH)
		size = HEIGHT;
	z.re = (x - WIDTH / 2.0) * (vars->params.radius + vars->params.radius) / size;
	z.im = (HEIGHT / 2.0 - y) * (vars->params.radius + vars->params.radius) / size;
	r_squared = vars->params.radius * vars->params.radius;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= r_squared && iter++ < vars->params.max_iter)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + vars->params.julia_c.re;
		z.im = 2 * temp * z.im + vars->params.julia_c.im;
	}
	if (iter > vars->params.max_iter)
		return (0);
	else
	{
		iter = (int)((double)iter / vars->params.max_iter * 255.0);
		iter = 255 - iter;
		return (iter << 16 | iter << 8 | iter);
	}
}

int	check_mandelbrot_set(int x, int y)
{
	t_complex	z;
	t_complex	c;
	int		r_squared;
	int		iter;
	int		size;
	double		temp;
	
	size = WIDTH;
	if (HEIGHT < WIDTH)
		size = HEIGHT;
	c.re = (x - WIDTH / 2.0) * (ESCAPE_RADIUS + ESCAPE_RADIUS) / size;
	c.im = (HEIGHT / 2.0 - y) * (ESCAPE_RADIUS + ESCAPE_RADIUS) / size;
	z.re = 0;
	z.im = 0;
	r_squared = ESCAPE_RADIUS * ESCAPE_RADIUS;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= r_squared && iter++ < MAX_ITERATION)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * temp * z.im + c.im;
	}
	if (iter > MAX_ITERATION)
		return (0);
	else
	{
		iter = (int)((double)iter / MAX_ITERATION * 255.0);
		iter = 255 - iter;
		return (iter << 16 | iter << 8 |  iter);
	}
}

void	exit_print_param_info(t_vars *vars)
{
	static char	*str = "\nParameter format:\n\t[fractal type][escape radius][max iteration][real value][imaginary value]\n\nFractal type is integer:\n\t1) Julia set, 2) Mandelbrot set, 3) Newton fractal\n\nEscape radius and max iteration are integers.\n\nLast two parameters are floating point numbers and for Julia set.\n\n";

	if (write(2, str, get_len(str))) 
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_FAILURE);
}

void	exit_complete(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}

t_params	*process_params(int argc, char **argv, t_params *params)
{
	if (argc < 4)
		return (0);
	if (!get_int(argv[1], &(params->type)) || !(0 < params->type && params->type < 4))
		return (0);
	if (!get_int(argv[2], &(params->radius)))
		return (0);
	if (!get_int(argv[3], &(params->max_iter)))
		return (0);
	if (params->type == 1 && !get_double(argv[4], &(params->julia_c.re)))
		return (0);
	if (params->type == 1 && !get_double(argv[5], &(params->julia_c.im)))
		return (0);
	return (params);
}

void	draw_fractal(t_vars *vars)
{
	int		x_idx;
	int		y_idx;
	int		(*fp)(int, int, t_vars *);

	if (vars->params.type == 1)
		fp = &check_julia_set;
	x_idx = -1;
	while (++x_idx < WIDTH)
	{
		y_idx = -1;
		while (++y_idx < HEIGHT)
			my_mlx_pixel_put(&(vars->img), x_idx, y_idx, (*fp)(x_idx, y_idx, vars));
			//my_mlx_pixel_put(&(vars->data), x_idx, y_idx, check_julia_set(x_idx, y_idx));
			//my_mlx_pixel_put(&(vars->img), x_idx, y_idx, check_mandelbrot_set(x_idx, y_idx));
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.ptr, 0, 0);
}

int	key_press_handler(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		exit_complete(vars);
	draw_fractal(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");
	vars.img.ptr = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.ptr, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	if (!process_params(argc, argv, &(vars.params)))
		exit_print_param_info(&vars);
	mlx_hook(vars.win, 2, 1L<<0, key_press_handler, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
