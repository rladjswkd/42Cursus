#include "fractal.h"

static void	put_pixel_color(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
			put_pixel_color(&(vars->img), x_idx, y_idx, (*fp)(x_idx, y_idx, vars));
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.ptr, 0, 0);
}
