/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:56:11 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/25 21:53:15 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_game *game)
{
	double	x, y;

	game->r = game->pa - 30.0;
	if (game->r < 0)
		game->r += 360.0;
	if (game->r > 360.0)
		game->r -= 360.0;
	game->i = 0;
	while (game->i < WIN_WIDTH)
	{
		x = (cos(degtorad(game->r)) * 5);
		y = (sin(degtorad(game->r)) * 5);
		ft_drawl(game, x, y);
		game->i++;
		game->r += 60.0 / WIN_WIDTH;
		if (game->r < 0)
			game->r += 360.0;
		if (game->r > 360.0)
			game->r -= 360.0;
	}
	ft_drawceilling(game, 0);
}

int	key_hook2(int keycode, t_game *game)
{
	if (keycode == UP)
		game->keys[0] = 0;
	else if (keycode == DOWN)
		game->keys[1] = 0;
	else if (keycode == RIGHT)
		game->keys[2] = 0;
	else if (keycode == LEFT)
		game->keys[3] = 0;
	return (0);
}

int	key_hook1(int keycode, t_game *game)
{
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
	return (0);
}

void	get_player_angle(t_game *game, char c)
{
	if (c == 'N')
		game->pa = 270.0;
	else if (c == 'S')
		game->pa = 90.0;
	else if (c == 'W')
		game->pa = 180.0;
	else if (c == 'E')
		game->pa = 0;
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
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
				game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				game->px = j * 50;
				game->py = i * 50;
				get_player_angle(game, game->map[i][j]);
				game->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	get_tex_path(t_game *game)
{
	int	hi;

	game->no_tex = mlx_xpm_file_to_image(game->mlx, game->no_textr, &hi, &hi);
	if (!game->no_tex)
		ft_error("wrong texture path!!\n(north texture)");
	game->we_tex = mlx_xpm_file_to_image(game->mlx, game->we_textr, &hi, &hi);
	if (!game->we_tex)
		ft_error("wrong texture path!!\n(west texture)");
	game->so_tex = mlx_xpm_file_to_image(game->mlx, game->so_textr, &hi, &hi);
	if (!game->so_tex)
		ft_error("wrong texture path!!\n(south texture)");
	game->ea_tex = mlx_xpm_file_to_image(game->mlx, game->ea_textr, &hi, &hi);
	if (!game->ea_tex)
		ft_error("wrong texture path!!\n(east texture)");
	game->no_texadr = mlx_get_data_addr(game->no_tex, &game->bits_per_pixel1, &game->line_length1, &game->endian1);
	game->so_texadr = mlx_get_data_addr(game->so_tex, &game->bits_per_pixel2, &game->line_length2, &game->endian2);
	game->we_texadr = mlx_get_data_addr(game->we_tex, &game->bits_per_pixel3, &game->line_length3, &game->endian3);
	game->ea_texadr = mlx_get_data_addr(game->ea_tex, &game->bits_per_pixel4, &game->line_length4, &game->endian4);
}

void	ft_init(t_game *game)
{
	game->lineo = malloc(sizeof(float) * WIN_WIDTH);
	game->lineh = malloc(sizeof(float) * WIN_WIDTH);
	game->keys = calloc(sizeof(int), 4);
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HIGHT);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	get_tex_path(game);
	get_player_cord(game);
	game->pdx = cos(degtorad(game->pa)) * P_SPEED;
	game->pdy = sin(degtorad(game->pa)) * P_SPEED;
	draw_rays(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
}

int	ft_hook(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HIGHT);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	if (game->keys[0])
		ft_moveup(game);
	if (game->keys[1])
		ft_movedown(game);
	if (game->keys[2])
		ft_moveright(game);
	if (game->keys[3])
		ft_moveleft(game);
	draw_rays(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		ft_error("Error\nWrong Number Of Args\n");
	game = malloc(sizeof(t_game));
	parse(game, av[1]);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HIGHT, "cub3d");
	ft_init(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_hook1, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, key_hook2, game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
}
