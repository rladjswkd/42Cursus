#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*relative_path = "./teapot.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	win = mlx_new_window(mlx, img_width, img_height, "Hello World");
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
