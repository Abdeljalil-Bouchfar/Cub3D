/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:56:11 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/19 16:03:56 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str)
{
	printf("%s", str);
	exit (1);
}

void	draw_rays(t_game *game)
{
	double	x, y;

	game->r = game->pa - 30.0;
	if (game->r < 0)
		game->r += 360.0;
	if (game->r > 360.0)
		game->r -= 360.0;
	game->i = 0;
	while (game->i < 1080)
	{
		x = (cos(degtorad(game->r)) * 5);
		y = (sin(degtorad(game->r)) * 5);
		ft_drawl(game, x, y);
		game->i++;
		game->r += 60.0 / 1080.0;
		if (game->r < 0)
			game->r += 360.0;
		if (game->r > 360.0)
			game->r -= 360.0;
	}
	ft_drawc(game, 0);
}

int	key_hook2(int keycode, t_game *game)
{
	int hi;

	if (keycode == UP)
		game->keys[0] = 0;
	else if (keycode == DOWN)
		game->keys[1] = 0;
	else if (keycode == RIGHT)
		game->keys[2] = 0;
	else if (keycode == LEFT)
		game->keys[3] = 0;
	else if (keycode == SPACE)
	{
		game->keys[4] = 0;
		game->hand = mlx_xpm_file_to_image(game->mlx, "xpms/hand/hand1.xpm", &hi, &hi);
	}
	return (0);
}

int	key_hook1(int keycode, t_game *game)
{
	int hi;

	if (keycode == 53)
		ft_error("GAME CLOSED\n");
	else if (keycode == UP)
		game->keys[0] = 1;
	else if (keycode == DOWN)
		game->keys[1] = 1;
	else if (keycode == RIGHT)
		game->keys[2] = 1;
	else if (keycode == LEFT)
		game->keys[3] = 1;
	else if (keycode == E)
		ft_opendoor(game);
	else if (keycode == SPACE)
		game->keys[4] = 1;
	else if (keycode == Q)
		ft_build(game);
	else if (keycode == X)
		ft_destroy(game);
	else if (keycode == 47)
	{
		game->barn++;
		if (game->barn > 8)
			game->barn = 0;
		mlx_destroy_image(game->mlx, game->bar);
		game->bar = mlx_xpm_file_to_image(game->mlx, game->bartex[game->barn], &hi, &hi);
	}
	else if (keycode == 43)
	{
		game->barn--;
		if (game->barn < 0)
			game->barn = 8;
		mlx_destroy_image(game->mlx, game->bar);
		game->bar = mlx_xpm_file_to_image(game->mlx, game->bartex[game->barn], &hi, &hi);
	}
	// else if (keycode == W)
	// 	game->offset += 3;
	return (0);
}

void	get_player_cord(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->px = j * 50;
				game->py = i * 50;
				game->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	get_img_path(t_game *game)
{
	int	hi;

	game->lineo = malloc(sizeof(float) * 1080);
	game->lineh = malloc(sizeof(float) * 1080);
	game->keys = calloc(sizeof(int), 5);
	game->pix = 1000;
	game->offset = 3;
	game->cpa = 3;
	game->barn = 0;
	game->img = mlx_new_image(game->mlx, 1080, 1080);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	game->pa = 90.0;
	game->pdx = cos(degtorad(game->pa)) * P_SPEED;
	game->pdy = sin(degtorad(game->pa)) * P_SPEED;
	get_player_cord(game);
	game->tex1 = mlx_xpm_file_to_image(game->mlx, "xpms/stone/stone.xpm", &hi, &hi);
	game->tadr1 = mlx_get_data_addr(game->tex1, &game->bits_per_pixel1, &game->line_length1, &game->endian1);
	game->sky = mlx_xpm_file_to_image(game->mlx, "xpms/sky/sky5.xpm", &hi, &hi);
	game->skyadr = mlx_get_data_addr(game->sky, &game->bits_per_pixel5, &game->line_length5, &game->endian5);
	game->door = mlx_xpm_file_to_image(game->mlx, "xpms/door/door.xpm", &hi, &hi);
	game->dooradr = mlx_get_data_addr(game->door, &game->bits_per_pixel6, &game->line_length6, &game->endian6);
	game->door2 = mlx_xpm_file_to_image(game->mlx, "xpms/door/door2.xpm", &hi, &hi);
	game->door2adr = mlx_get_data_addr(game->door2, &game->bits_per_pixel8, &game->line_length8, &game->endian8);
	game->floor = mlx_xpm_file_to_image(game->mlx, "xpms/floor/floor.xpm", &hi, &hi);
	game->flooradr = mlx_get_data_addr(game->floor, &game->bits_per_pixel7, &game->line_length7, &game->endian7);
	creat_str_bar(game);
	game->bar = mlx_xpm_file_to_image(game->mlx, game->bartex[game->barn], &hi, &hi);
	game->hand = mlx_xpm_file_to_image(game->mlx, "xpms/hand/hand1.xpm", &hi, &hi);
	draw_rays(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->hand, 850, 900);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->bar, 170, 920);
}

int	ft_hook(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, 1080, 1080);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	if (game->keys[4])
		ft_anime(game);
	if (game->keys[0])
	{
		game->offset *= -1;
		game->cpa *= -1;
		ft_moveup(game);
	}
	if (game->keys[1])
	{
		game->offset *= -1;
		game->cpa *= -1;
		ft_movedown(game);
	}
	if (game->keys[2])
		ft_moveright(game);
	if (game->keys[3])
		ft_moveleft(game);
	draw_rays(game);
	game->pix+=3;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->hand, 0+game->cpa, 500+game->offset);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->bar, 170, 920);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		ft_error("Error\nWrong Number Of Args\n");
	game = malloc(sizeof(t_game));
	ft_map(game, av[1]);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1080, 1080, "cub3d");
	get_img_path(game);
	mlx_hook(game->mlx_win, 3, 1L << 1, key_hook2, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_hook1, game);
	mlx_hook(game->mlx_win, 6, 0, key_hook1, game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
}
