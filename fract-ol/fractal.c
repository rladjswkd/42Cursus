/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:35:28 by gyepark           #+#    #+#             */
/*   Updated: 2022/04/14 17:00:28 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_complex	transpose(int x, int y, t_vars *vars)
{
	t_complex	res;

	res.re = (double)x * (vars->scr.frame_max.re - vars->scr.frame_min.re)
		/ SIZE + vars->scr.frame_min.re;
	res.im = -(double)y * (vars->scr.frame_max.im - vars->scr.frame_min.im)
		/ SIZE + vars->scr.frame_max.im;
	return (res);
}

static int	check_divergence(t_complex *z, t_complex c, int rr, int max_iter)
{
	int		iter;
	double	temp;

	iter = 0;
	while (z->re * z->re + z->im * z->im <= rr && iter++ < max_iter)
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
	int			rr;
	int			iter;

	z = transpose(x, y, vars);
	c = vars->params.julia_c;
	rr = vars->params.radius * vars->params.radius;
	iter = check_divergence(&z, c, rr, vars->params.max_iter);
	return (get_iter_color(iter, z, vars));
}

int	check_mandelbrot_set(int x, int y, t_vars *vars)
{
	t_complex	z;
	t_complex	c;
	int			rr;
	int			iter;

	z.re = 0;
	z.im = 0;
	c = transpose(x, y, vars);
	rr = vars->params.radius * vars->params.radius;
	iter = check_divergence(&z, c, rr, vars->params.max_iter);
	return (get_iter_color(iter, z, vars));
}
