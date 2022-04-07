#include "fractal.h"

static void	move_point(t_vars *vars, double val_x, double val_y)
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
	vars->scr.mouse = (t_complex){0, 0};
	if (vars->zoom_mode)
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
