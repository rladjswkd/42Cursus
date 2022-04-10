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
	int	palette[16] = {
		    get_rgb(66, 30, 15), get_rgb(25, 7, 26), get_rgb(9, 1, 47),
		    get_rgb(4, 4, 73), get_rgb(0, 7, 100),
		    get_rgb(12, 44, 138), get_rgb(24, 82, 177),
		    get_rgb(57, 125, 209), get_rgb(134, 181, 229),
		    get_rgb(211, 236, 248), get_rgb(241, 233, 191),
		    get_rgb(248, 201, 95), get_rgb(255, 170, 0),
		    get_rgb(204, 128, 0), get_rgb(153, 87, 0),
		    get_rgb(106, 52, 3)
	};
	int	color1;
	int	color2;
	double	continuous;

	if (iter > vars->params.max_iter)
		return (0x000000);
	continuous = iter - (log((log(z.re * z.re + z.im * z.im) / 2.0) / log(vars->params.radius)) / log(2));
	color1 = palette[(int)floor(continuous) % 16] + vars->color_val;
	color2 = palette[(int)floor(continuous) % 16 + 1] + vars->color_val;
	return (interpolate_linearly(color1, color2, continuous - floor(continuous)));
}
