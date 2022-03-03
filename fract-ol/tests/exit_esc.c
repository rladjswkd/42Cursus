#include <mlx.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

int	close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 0xFF, 0xFF, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
