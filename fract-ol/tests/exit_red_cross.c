#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

int	print(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 0xFF, 0xFF, "Hello world!");
	mlx_hook(vars.win, 17, 1L<<17, print, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
