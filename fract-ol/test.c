#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#define EVENT_KEY		114//15
#define ESC_KEY			53//65307
#define WHEELUP			4
#define WHEELDOWN		5
#define WIDTH			1000
#define HEIGHT			1000
#define SIZE			1000

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

typedef	struct	s_screen
{
	double	zoom_rate;
	double	scale;
	int		x_start;
	int		y_start;
	int		img_width;
	int		img_height;
}		t_screen;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_img		img;
	t_params	params;
	t_screen	scr;
	int		effect_val;
}		t_vars;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
// 안씀.
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

int	get_sign(char **str)
{
       	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
		if (*((*str)++) == '-')
			sign = -1;
	return (sign);
}

double	*get_double(char *str, double *val)
{
	long double	temp;
	double		scale;
       	int		sign;

	sign = get_sign(&str);
	temp = 0;
	while (47 < *str && *str < 58)
		temp = temp * 10 + sign * (*(str++) - 48);
	if (*str != '.' && *str != '\0')
		return (0);
	*val = (double)temp;
	if (*str == '\0')
		return (val);
	str++;
	scale = 10;
	while (47 < *str && *str < 58)
	{
		temp += sign * (*(str++) - 48) / scale;
		scale *= 10;
	}
	if (*str != '\0')
		return (0);
	*val = (double)temp;
	return (val);
}

int	*get_int(char *str, int *val)
{
	int	sign;

	sign = get_sign(&str);
	*val = 0;
	while (47 < *str && *str < 58)
		*val = *val * 10 + sign * (*(str++) - 48);
	if (*str != '\0')
		return (0);
	return (val);
}

t_complex	get_transposed_point(int x, int y, t_vars *vars)
{
	t_complex	res;

	res.re = (x - WIDTH / 2.0) * (vars->params.radius + vars->params.radius) / SIZE / vars->scr.scale;
	res.im = (HEIGHT / 2.0 - y) * (vars->params.radius + vars->params.radius) / SIZE / vars->scr.scale;
	return (res);
}

int	check_divergence(t_complex z, t_complex c, int squared, int max_iter)
{
	int		iter;
	double		temp;

	iter = 0;
	while (z.re * z.re + z.im * z.im <= squared && iter++ < max_iter)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * temp * z.im + c.im;
	}
	return (iter);
}

int	get_iter_color(int iter, int max_iter)
{
	if (iter == max_iter)
		return (0);
	iter = (int)((double)iter / max_iter * 255.0);
	iter = 255 - iter;
	return (iter << 16 | iter << 8 | iter);
}

int	check_julia_set(int x, int y, t_vars *vars)
{
	t_complex	z;
	t_complex	c;
	int		squared;
	int		iter;
	
	z = get_transposed_point(x, y, vars);
	c = vars->params.julia_c;
	squared = vars->params.radius * vars->params.radius;
	iter = check_divergence(z, c, squared, vars->params.max_iter);
	return (get_iter_color(iter, vars->params.max_iter));
}

int	check_mandelbrot_set(int x, int y, t_vars *vars)
{
	t_complex	z;
	t_complex	c;
	int		squared;
	int		iter;
	
	z.re = 0;
	z.im = 0;
	c = get_transposed_point(x, y, vars);
	squared = vars->params.radius * vars->params.radius;
	iter = check_divergence(z, c, squared, vars->params.max_iter);
	return (get_iter_color(iter, vars->params.max_iter));
}
void	exit_print_param_info(t_vars *vars)
{
	char	*str;

	str = "\nParameter format:\n\t[fractal type][escape radius][max iteration][real value][imaginary value]\n\nFractal type is integer:\n\t1) Julia set, 2) Mandelbrot set, 3) Newton fractal\n\nEscape radius and max iteration are integers.\n\nLast two parameters are floating point numbers and for Julia set.\n\n";

	if (write(2, str, get_len(str))) // remove if statements on mac
	{}
	mlx_destroy_image(vars->mlx, vars->img.ptr);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(EXIT_FAILURE);
}

void	exit_complete(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.ptr);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}

t_params	*process_params(int argc, char **argv, t_params *params)
{
	if (argc < 4)
		return (0);
	if (!get_int(argv[1], &(params->type))
			|| !(0 < params->type && params->type < 4))
		return (0);
	if (!get_int(argv[2], &(params->radius)))
		return (0);
	if (!get_int(argv[3], &(params->max_iter)))
		return (0);
	if (params->type == 1 && argc < 6)
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
	else if (vars->params.type == 2)
		fp = &check_mandelbrot_set;
	else
		fp = 0;
	x_idx = -1;
	while (++x_idx < WIDTH)
	{
		y_idx = -1;
		while (++y_idx < HEIGHT)
			my_mlx_pixel_put(&(vars->img), x_idx, y_idx, (*fp)(vars->scr.x_start + x_idx, vars->scr.y_start + y_idx, vars));
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.ptr, 0, 0);
}

int	key_press_handler(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		exit_complete(vars);
	return (0);
}

int	base_handler(t_vars *vars)
{
	// for psychedelic effects.
	//vars->effect_val
	draw_fractal(vars);
	return (0);
}

void	zoom_in(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	vars->scr.scale /= vars->scr.zoom_rate;
}

void	zoom_out(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	vars->scr.scale *= vars->scr.zoom_rate;
}

int	zoom_handler(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == WHEELUP)
		zoom_in(vars);
	else if (button == WHEELDOWN)
		zoom_out(vars);
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
	vars.scr.zoom_rate = 1.1;
	vars.scr.scale = 1;
	vars.scr.x_start = 0;
	vars.scr.y_start = 0;
	vars.scr.img_width = WIDTH;
	vars.scr.img_height = HEIGHT;
	//vars.effect_val = 0;
	mlx_hook(vars.win, 2, 1L<<0, key_press_handler, &vars);
	mlx_hook(vars.win, 4, 1L<<2, zoom_handler, &vars);
	mlx_loop_hook(vars.mlx, base_handler, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
