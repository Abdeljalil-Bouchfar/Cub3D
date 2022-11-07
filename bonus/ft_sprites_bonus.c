/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:19:30 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/07 15:48:03 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_drawline5(t_game *game, float y1, double lineh, float x)
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
		dst = game->spriteadr[game->index / 2] + (int)(i * (S_W / lineh)) % S_W
			* game->ll2[game->index / 2] + (int)(x * S_W / 50) % S_W
			* (game->bpp2[game->index / 2] / 8);
		if (*(unsigned int *)dst != 0xFF000000)
			my_mlx_pixel_put(game, game->i, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}

void	ft_3dsprite(t_game *game, double x, double y, int i)
{
	double	lineh;
	double	lineo;
	double	ch;
	double	ca;
	double	len;

	ca = fixang(game->pa - game->r);
	len = dist(game->px, game->py, x, y);
	len = len * cos(degtorad(ca));
	lineh = (50 * WIN_HIGHT) / len;
	ch = lineh;
	if (lineh > WIN_HIGHT)
		lineh = WIN_HIGHT;
	lineo = (WIN_HIGHT / 2) - (lineh / 2);
	if (i == 1)
		ft_drawline5(game, lineo, ch, x);
	else
		ft_drawline5(game, lineo, ch, y);
}

void	ft_sprite2(t_game *game, double x, double y)
{
	double	x2;
	double	y2;

	x2 = cos(degtorad(game->r));
	y2 = sin(degtorad(game->r));
	while (1)
	{
		if (game->map[(int)y / 50][(int)(x + x2) / 50] == '4')
		{
			x += x2;
			ft_3dsprite(game, x, y, 0);
			return ;
		}
		if (game->map[(int)(y + y2) / 50][(int)x / 50] == '4')
		{
			y += y2;
			ft_3dsprite(game, x, y, 1);
			return ;
		}
		if (game->map[(int)(y + y2) / 50][(int)(x + x2) / 50] != '0'
			&& game->map[(int)(y + y2) / 50][(int)(x + x2) / 50] != '3')
			return ;
		x += x2;
		y += y2;
	}
}

void	ft_sprite(t_game *game, double x2, double y2)
{
	double	x;
	double	y;

	x = game->px;
	y = game->py;
	while (1)
	{
		if (game->map[(int)(y + y2) / 50][(int)(x + x2) / 50] == '4')
		{
			ft_sprite2(game, x, y);
			return ;
		}
		if (game->map[(int)(y + y2) / 50][(int)(x + x2) / 50] != '0'
			&& game->map[(int)(y + y2) / 50][(int)(x + x2) / 50] != '3')
			return ;
		x += x2;
		y += y2;
	}
}
