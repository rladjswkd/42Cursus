#include <mlx.h>
#include <stdio.h>
#include <time.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	time_t	t;
}		t_vars;

int	press_key(int keycode, t_vars *vars)
{
	(void)keycode;
	if (!vars->t)
		vars->t = time(0);
	return (0);
}

int	release_key(int keycode, t_vars *vars)
{
	(void)keycode;
	if (time(0) - vars->t > 5)
		printf("%s\n", "pressing more than 5 seconds.");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 0xFF, 0xFF, "Hello world!");
	vars.t = 0;
	mlx_hook(vars.win, 2, 1L<<0, press_key, &vars);
	mlx_hook(vars.win, 3, 1L<<1, release_key, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
