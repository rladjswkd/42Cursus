#include "fractal.h"

t_complex	transpose(int x, int y, t_vars *vars)
{
	t_complex	res;
	
	res.re = (double)x / SIZE * (vars->scr.frame_max.re - vars->scr.frame_min.re)
		+ vars->scr.frame_min.re;
	res.im = -(double)y / SIZE * (vars->scr.frame_max.im - vars->scr.frame_min.im)
		+ vars->scr.frame_max.im;
	return (res);
}

static int	check_divergence(t_complex *z, t_complex c, int squared, int max_iter)
{
	int		iter;
	double	temp;
	
	iter = 0;
	while (z->re * z->re + z->im * z->im <= squared && iter++ < max_iter)
	{
		temp = z->re;
		z->re = z->re * z->re - z->im * z->im + c.re;
		z->im = 2 * temp * z->im + c.im;
	}
	return (iter);
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
	iter = check_divergence(&z, c, squared, vars->params.max_iter);
	return (get_iter_color(iter, z, vars));
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
	iter = check_divergence(&z, c, squared, vars->params.max_iter);
	return (get_iter_color(iter, z, vars));
}
