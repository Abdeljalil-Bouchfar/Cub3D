/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:19:30 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/03 15:20:59 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_3dsprite(t_game *game, double x, double y, int i)
{
	double	lineh, ch;
	float	lineo;
	double	ca, len;

	ca = game->pa - game->r;
	if (ca < 0)
		ca += 360;
	if (ca > 360)
		ca -= 360;
	len = dist(game->px, game->py, x, y);
	len = len * cos(degtorad(ca));
	lineh = (50*WIN_HIGHT) / len;
	ch = lineh;
	if (lineh > WIN_HIGHT)
		lineh = WIN_HIGHT;
	lineo = (WIN_HIGHT/2) - (lineh / 2);
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
		if (game->map[(int)y / 50][(int)(x + x2 / 64) / 50] == '4')
		{
			x += x2 / 64;
			ft_3dsprite(game, x, y, 0);
			ft_3dsprite(game, x+8, y+8, 0);
			return ;
		}
		if (game->map[(int)(y + y2 / 64) / 50][(int)x / 50] == '4')
		{
			y += y2 / 64;
			ft_3dsprite(game, x, y, 1);
			ft_3dsprite(game, x+8, y+8, 1);
			return ;
		}
		if (game->map[(int)y / 50][(int)(x + x2 / 64) / 50] == '1')
			return ;
		if (game->map[(int)(y + y2 / 64) / 50][(int)x / 50] == '1')
			return ;
		x += x2 / 64;
		y += y2 / 64;
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
		if (game->map[(int)(y) / 50][(int)(x + x2) / 50] == '4')
		{
			ft_sprite2(game, x, y);
			return ;
		}
		if (game->map[(int)(y + y2) / 50][(int)(x) / 50] == '4')
		{
			ft_sprite2(game, x, y);
			return ;
		}
		if (game->map[(int)y / 50][(int)(x + x2) / 50] == '1')
			return ;
		if (game->map[(int)(y + y2) / 50][(int)x / 50] == '1')
			return ;
		x += x2;
		y += y2;
	}
}
