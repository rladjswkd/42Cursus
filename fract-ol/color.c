/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:09:26 by gyepark           #+#    #+#             */
/*   Updated: 2022/04/14 20:29:56 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	interpolate_linearly(int c1, int c2, double frac)
{
	int	r;
	int	g;
	int	b;

	r = c1 >> 16 & 0xff;
	g = c1 >> 8 & 0xff;
	b = c1 & 0xff;
	return (get_rgb((int)(((c2 >> 16 & 0xff) - r) * frac + r),
		(int)(((c2 >> 8 & 0xff) - g) * frac + g),
		(int)(((c2 & 0xff) - b) * frac + b)
		));
}

int	get_iter_color(int iter, t_complex z, t_vars *vars)
{
	static int	palette[16] = {
		0x421e0f, 0x19071a, 0x09012f, 0x040449, 0x000764, 0x0c2c8a, 0x1852b1,
		0x397dd1, 0x86b5e5, 0xd3ecf8, 0xf1e9bf, 0xf8c95f, 0xffaa00, 0xcc8000,
		0x995700, 0x6a3403
	};
	int			color1;
	int			color2;
	double		frac;

	if (iter > vars->params.max_iter)
		return (0x000000);
	frac = iter
		- log((log(z.re * z.re + z.im * z.im) / 2) / log(vars->params.radius))
		/ log(2);
	color1 = palette[(int)floor(frac) % 16] + vars->color_val;
	color2 = palette[(int)floor(frac) % 16 + 1] + vars->color_val;
	return (interpolate_linearly(color1, color2, frac - floor(frac)));
}
