/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:11:53 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/28 15:43:10 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_drawline3(t_game *game, float y1, double lineh, float x)
{
	char	*dst;
	int		i;

	i = 0;
	if (lineh > WIN_HIGHT)
		i = (lineh - WIN_HIGHT) / 2;
	while (i < lineh)
	{
		if (y1 >= WIN_HIGHT)
			break ;
		if (game->r >= 180.0 && game->r <= 360.0)
			dst = game->no_texadr + (int)(i * (N_W / lineh)) % N_W * game->llen1
				+ (int)(x * N_W / 50) % N_W * (game->bpp1 / 8);
		if (game->r >= 0 && game->r <= 180.0)
			dst = game->so_texadr + (int)(i * (S_W / lineh)) % S_W * game->llen2
				+ (int)(x * S_W / 50) % S_W * (game->bpp2 / 8);
		my_mlx_pixel_put(game, game->i, y1, *(unsigned int *)dst); // TODO: SEGV, run ./cub3d maps/{e b}.cub
		y1++;
		i++;
	}
}

void	draw_rays(t_game *game)
{
	double	x;
	double	y;

	game->r = game->pa - 30.0;
	game->r = fixang(game->r);
	game->i = 0;
	while (game->i < WIN_WIDTH)
	{
		x = (cos(degtorad(game->r)) * 5);
		y = (sin(degtorad(game->r)) * 5);
		ft_castray1(game, x, y);
		game->i++;
		game->r += 60.0 / WIN_WIDTH;
		game->r = fixang(game->r);
	}
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
	else if (keycode == ROTATE_RIGHT)
		game->keys[4] = 0;
	else if (keycode == ROTATE_LEFT)
		game->keys[5] = 0;
	
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
	else if (keycode == ROTATE_RIGHT)
		game->keys[4] = 1;
	else if (keycode == ROTATE_LEFT)
		game->keys[5] = 1;
	return (0);
}

int	ft_hook(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HIGHT);
	game->addr = mlx_get_data_addr(game->img, &game->bpp,
			&game->llen, &game->en);
	if (game->keys[0])
		ft_moveup(game);
	if (game->keys[1])
		ft_movedown(game);
	if (game->keys[4])
		ft_rotateright(game);
	if (game->keys[5])
		ft_rotateleft(game);
	if (game->keys[2])
		ft_moveright(game);
	if (game->keys[3])
		ft_moveleft(game);
	draw_rays(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
	return (0);
}
