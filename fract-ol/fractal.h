#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# define ESC_KEY	65307//53
# define ZOOM_KEY	122
# define COLOR_KEY	99//8
# define WHEELUP	4
# define WHEELDOWN	5
# define LEFT		65361
# define UP		65362
# define RIGHT		65363
# define DOWN		65364
# define WIDTH		1000
# define HEIGHT		1000
# define SIZE		1000

typedef struct	s_complex
{
	double	re;
	double	im;
}		t_complex;

typedef struct	s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_params
{
	int		type;
	int		radius;
	int		max_iter;
	t_complex	julia_c;
}		t_params;

typedef	struct	s_screen
{
	t_complex	mouse;
	t_complex	frame_min;
	t_complex	frame_max;
}		t_screen;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_img		img;
	t_params	params;
	t_screen	scr;
	int		zoom_mode;
	int		color_flag;
	int		color_val;
}		t_vars;

int		get_iter_color(int iter, t_complex z, t_vars *vars);
void		draw_fractal(t_vars *vars);
t_complex	transpose(int x, int y, t_vars *vars);
int		check_julia_set(int x, int y, t_vars *vars);
int		check_mandelbrot_set(int x, int y, t_vars *vars);
int		key_press_handler(int keycode, t_vars *vars);
int		base_handler(t_vars *vars);
int		zoom_handler(int button, int x, int y, t_vars *vars);
int		check_newton(int x, int y, t_vars *vars);
t_complex	divide_func_derivative(t_complex v);
void		exit_print_param_info(t_vars *vars);
void		exit_complete(t_vars *vars);
t_params	*process_params(int argc, char **argv, t_params *params);
int		get_rgb(int r, int g, int b);
int		get_len(char *str);
double		*get_double(char *str, double *val);
int		*get_int(char *str, int *val);
#endif
