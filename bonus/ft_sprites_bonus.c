/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:19:30 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/04 18:21:17 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_3dsprite(t_game *game, double x, double y, int i)
{
	double	lineh, ch;
	float	lineo;
	double	ca, len;

	ca = fixang(game->pa - game->r);
	len = dist(game->px, game->py, x, y);
	len = len * cos(degtorad(ca));
	lineh = (50*WIN_HIGHT) / len;
	ch = lineh;
	if (lineh > WIN_HIGHT)
		lineh = WIN_HIGHT;
	lineo = (WIN_HIGHT/2) - (lineh / 2);
	lineo += game->offset;
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
		if (game->map[(int)y / 50][(int)(x + x2 / 8) / 50] == '4')
		{
			x += x2 / 8;
			ft_3dsprite(game, x, y, 0);
			ft_3dsprite(game, x+5, y+5, 0);
			return ;
		}
		else if (game->map[(int)y / 50][(int)(x + x2 / 8) / 50] == '2')
		{
			x += x2 / 8;
			ft_3dscene2(game, x, y, 0);
			return ;
		}
		if (game->map[(int)(y + y2 / 8) / 50][(int)x / 50] == '4')
		{
			y += y2 / 8;
			ft_3dsprite(game, x, y, 1);
			ft_3dsprite(game, x+5, y+5, 1);
			return ;
		}
		else if (game->map[(int)(y + y2 / 8) / 50][(int)x / 50] == '2')
		{
			y += y2 / 8;
			ft_3dscene2(game, x, y, 1);
			return ;
		}
		if (game->map[(int)y / 50][(int)(x + x2 / 8) / 50] == '1')
			return ;
		if (game->map[(int)(y + y2 / 8) / 50][(int)x / 50] == '1')
			return ;
		x += x2 / 8;
		y += y2 / 8;
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
		if (game->map[(int)(y + y2) / 50][(int)(x + x2) / 50] == '4' || game->map[(int)(y + y2) / 50][(int)(x + x2) / 50] == '2')
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
