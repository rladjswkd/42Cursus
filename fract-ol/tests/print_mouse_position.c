#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

int	enter_mouse(int x, int y, void *param)
{
	(void)param;
	printf("x: %d, y: %d\n", x, y);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 0xFF, 0xFF, "Hello world!");
	mlx_hook(vars.win, 6, 1L<<6, enter_mouse, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
