#include "fractal.h"

static int	is_close_to_roots(t_complex v)
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
