#include "fractal.h"

void	exit_print_param_info(t_vars *vars)
{
	char	*str;

	str = "\nParameter format:\n\t[fractal type][escape radius]\
		[max iteration][real value][imaginary value]\n\n\
		Fractal type is integer:\n\t\
		1) Julia set, 2) Mandelbrot set, 3) Newton fractal\n\n\
		Escape radius and max iteration are integers.\n\n\
		Last two parameters are floating point numbers\
		and for Julia set.\n\n";

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


