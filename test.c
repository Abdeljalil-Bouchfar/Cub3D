#include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     printf("{%s}\n", dst);
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
//     int i;
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_xpm_file_to_image(mlx, "cloud.xpm", &i, &i);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 540, 200, 0);
// 	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	//mlx_loop(mlx);
// }
#include <stdio.h>
#include <math.h>
#include <string.h>
double	degtorad(double a)
{
	return (a * M_PI / 180.0);
}

int main()
{
	char str[] = "😀";
	// for(int i =0; i < 5; ++i)
	// {
	// 	sleep(1);
	// }
	write(1, "😀", 2);
	write(1, "😀"+1, 2);
}