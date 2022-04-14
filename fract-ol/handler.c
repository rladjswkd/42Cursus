/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:28:04 by gyepark           #+#    #+#             */
/*   Updated: 2022/04/14 15:28:06 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

static void	move_point(t_vars *vars, double val_x, double val_y)
{
	vars->scr.frame_max.re += val_x;
	vars->scr.frame_min.re += val_x;
	vars->scr.frame_max.im += val_y;
	vars->scr.frame_min.im += val_y;
}

int	key_press_handler(int keycode, t_vars *vars)
{
	double	dw;
	double	dh;

	printf("%d\n", keycode);
	if (keycode == ESC_KEY)
		exit_complete(vars);
	if (keycode == ZOOM_KEY)
	{
		vars->zoom_mode = !(vars->zoom_mode);
		return (0);
	}
	if (keycode == COLOR_KEY)
	{
		vars->color_flag = !(vars->color_flag);
		vars->color_val = 0;
		return (0);
	}
	dw = (vars->scr.frame_max.re - vars->scr.frame_min.re) * 0.05;
	dh = (vars->scr.frame_max.im - vars->scr.frame_min.im) * 0.05;
	move_point(vars, -dw * (keycode == LEFT) + dw * (keycode == RIGHT),
		dh * (keycode == UP) - dh * (keycode == DOWN));
	return (0);
}

int	base_handler(t_vars *vars)
{
	if (vars->color_flag)
		vars->color_val += 0x00222222;
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
