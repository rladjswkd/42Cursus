#include "fractal.h"

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
