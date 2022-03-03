#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

int	enter_mouse(int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	printf("%s\n", "hello!");
	return (0);
}

int	leave_mouse(int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	printf("%s\n", "bye!");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 0xFF, 0xFF, "Hello world!");
	mlx_hook(vars.win, 7, 1L<<4, enter_mouse, &vars);
	mlx_hook(vars.win, 8, 1L<<5, leave_mouse, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
