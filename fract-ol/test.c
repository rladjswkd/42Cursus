#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#define ESC_KEY			53//65307
#define ZOOM_KEY		99
#define WHEELUP			4
#define WHEELDOWN		5
#define LEFT			65361
#define	UP			65362
#define	RIGHT			65363
#define	DOWN			65364
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
	t_complex	mouse;
	t_complex	frame_min;
	t_complex	frame_max;
}		t_screen;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_img		img;
	t_params	params;
	t_screen	scr;
	int		zoom_mode;
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

t_complex	transpose(int x, int y, t_vars *vars)
{
	t_complex	res;
	
	res.re = (double)x / SIZE * (vars->scr.frame_max.re - vars->scr.frame_min.re)
		+ vars->scr.frame_min.re;
	res.im = -(double)y / SIZE * (vars->scr.frame_max.im - vars->scr.frame_min.im)
		+ vars->scr.frame_max.im;
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
	if (iter > max_iter)
		return (0x0);
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
	
	z = transpose(x, y, vars);
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
	c = transpose(x, y, vars);
	squared = vars->params.radius * vars->params.radius;
	iter = check_divergence(z, c, squared, vars->params.max_iter);
	return (get_iter_color(iter, vars->params.max_iter));
}

t_complex	get_complex_pow_2(t_complex v)
{
	t_complex	res;
	double		temp_re;

	temp_re = v.re;
	res.re = v.re * v.re - v.im * v.im;
	res.im = 2 * temp_re * v.im;
	return (res);
}

t_complex	get_complex_pow_3(t_complex v)
{
	t_complex	res;

	res.re = pow(v.re, 3) - 3 * v.re * v.im * v.im;
	res.im = -pow(v.im, 3) + 3 * v.re * v.re * v.im;
	return (res);
}

t_complex	get_func_value(t_complex v)
{
	t_complex	res;

	res = get_complex_pow_3(v);
	res.re -= 1;
	return (res);
}

t_complex	get_derivative_value(t_complex v)
{
	t_complex	res;

	res = get_complex_pow_2(v);
	res.re *= 3;
	res.im *= 3;
	return (res);
}

t_complex	divide_func_derivative(t_complex v)
{
	t_complex	res;
	t_complex	p;
	t_complex	p_prime;
	double		divider;

	p = get_func_value(v);
	p_prime = get_derivative_value(v);
	divider = p_prime.re * p_prime.re + p_prime.im * p_prime.im;
	res.re = (p.re * p_prime.re + p.im * p_prime.im) / divider;
	res.im = (p.im * p_prime.re - p.re * p_prime.im) / divider;
	return (res);
}

int	is_close_to_roots(t_complex v)
{
	double		tol;
	t_complex	roots[3]; 
	
	tol = 0.000001;
	roots[0] = (t_complex){1, 0};
	roots[1] = (t_complex){-0.5, sqrt(3)/2.0};
	roots[2] = (t_complex){-0.5, -sqrt(3)/2.0};
	if (fabs(v.re - roots[0].re) < tol && fabs(v.im - roots[0].im) < tol)
		return (0);
	else if (fabs(v.re - roots[1].re) < tol && fabs(v.im - roots[1].im) < tol)
		return (1);
	else if (fabs(v.re - roots[2].re) < tol && fabs(v.im - roots[2].im) < tol)
		return (2);
	return (-1);
}

int	check_newton(int x, int y, t_vars *vars)
{
	t_complex	z;
	t_complex	minus;
	int			iter;
	int			color_idx;
	static int	color[3] = {0x0000FF, 0x00FF00, 0xFF0000};

	z = transpose(x, y, vars);
	iter = 0;
	while (iter++ < vars->params.max_iter)
	{
		minus = divide_func_derivative(z);
		z.re -= minus.re;
		z.im -= minus.im;
		color_idx = is_close_to_roots(z);
		if (color_idx > -1)
			return (color[color_idx]);
	}
	return (0);
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
		fp = &check_newton;
	x_idx = -1;
	while (++x_idx < WIDTH)
	{
		y_idx = -1;
		while (++y_idx < HEIGHT)
			my_mlx_pixel_put(&(vars->img), x_idx, y_idx, (*fp)(x_idx, y_idx, vars));
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.ptr, 0, 0);
}

void	move_point(t_vars *vars, double val_x, double val_y)
{
	vars->scr.frame_max.re += val_x;
	vars->scr.frame_min.re += val_x;
	vars->scr.frame_max.im += val_y;
	vars->scr.frame_min.im += val_y;
}

int	key_press_handler(int keycode, t_vars *vars)
{
	double	w;
	double	h;

	if (keycode == ESC_KEY)
		exit_complete(vars);
	if (keycode == ZOOM_KEY)
	{
		vars->zoom_mode = !(vars->zoom_mode);
		return (0);
	}
	w = vars->scr.frame_max.re - vars->scr.frame_min.re;
	h = vars->scr.frame_max.im - vars->scr.frame_min.im;
	if (keycode == LEFT)
		move_point(vars, -w * 0.05, 0);
	else if (keycode == RIGHT)
		move_point(vars, w * 0.05, 0);
	else if (keycode == UP)
		move_point(vars, 0, h * 0.05);
	else if (keycode == DOWN)
		move_point(vars, 0, -h * 0.05);
	return (0);
}

int	base_handler(t_vars *vars)
{
	// for psychedelic effects.
	//vars->effect_val
	draw_fractal(vars);
	return (0);
}

int	zoom_handler(int button, int x, int y, t_vars *vars)
{
	double	rate;

	if (button != WHEELUP && button != WHEELDOWN)
		return (0);
	rate = 1.1;
	if (button == WHEELDOWN)
		rate = 1 / 1.1;
	vars->scr.mouse = transpose(x, y, vars);
	vars->scr.frame_max.re = vars->scr.mouse.re
		+ (vars->scr.frame_max.re - vars->scr.mouse.re) * rate;
	vars->scr.frame_max.im = vars->scr.mouse.im
		+ (vars->scr.frame_max.im - vars->scr.mouse.im) * rate;
	vars->scr.frame_min.re = vars->scr.mouse.re
		+ (vars->scr.frame_min.re - vars->scr.mouse.re) * rate;
	vars->scr.frame_min.im = vars->scr.mouse.im
		+ (vars->scr.frame_min.im - vars->scr.mouse.im) * rate;
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
	vars.scr.frame_max.re = vars.params.radius;
	vars.scr.frame_max.im = vars.params.radius;
	vars.scr.frame_min.re = -vars.params.radius;
	vars.scr.frame_min.im = -vars.params.radius;
	vars.zoom_mode = 0;
	//vars.effect_val = 0;
	mlx_hook(vars.win, 2, 1L<<0, key_press_handler, &vars);
	mlx_hook(vars.win, 4, 1L<<2, zoom_handler, &vars);
	mlx_loop_hook(vars.mlx, base_handler, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
