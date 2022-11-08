/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:13:39 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/08 15:42:40 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_3dscene(t_game *game, float x, float y, int i)
{
	double	lineh;
	double	ch;
	double	lineo;
	double	ca;
	double	len;

	ca = fixang(game->pa - game->r);
	len = dist(game->px, game->py, x, y);
	len = len * cos(degtorad(ca));
	lineh = (50.0 * WIN_HIGHT) / len;
	ch = lineh;
	if (lineh > WIN_HIGHT)
		lineh = WIN_HIGHT;
	lineo = (WIN_HIGHT / 2.0) - (lineh / 2.0);
	if (i == 1)
		ft_drawline1(game, lineo, ch, x);
	else
		ft_drawline2(game, lineo, ch, y);
	ft_drawf(game, lineh, lineo);
	ft_drawc(game, lineo);
}

void	ft_3dscene2(t_game *game, float x, float y, int i)
{
	double	lineh;
	double	ch;
	double	lineo;
	double	ca;
	double	len;

	ca = fixang(game->pa - game->r);
	len = dist(game->px, game->py, x, y);
	len = len * cos(degtorad(ca));
	lineh = (50.0 * WIN_HIGHT) / len;
	ch = lineh;
	if (lineh > WIN_HIGHT)
		lineh = WIN_HIGHT;
	lineo = (WIN_HIGHT / 2) - (lineh / 2);
	if (i == 1)
		ft_drawline3(game, lineo, ch, x);
	else
		ft_drawline3(game, lineo, ch, y);
	ft_drawf(game, lineh, lineo);
	ft_drawc(game, lineo);
}

int	ft_wallordoor(t_game *game, double x, double y, char c)
{
	double	x2;
	double	y2;

	x2 = (cos(degtorad(game->r)) * 5);
	y2 = (sin(degtorad(game->r)) * 5);
	if (game->map[(int)y / 50][(int)(x + x2 / 20) / 50] == c)
	{
		x += x2 / 20;
		if (c == '1')
			ft_3dscene(game, x, y, 0);
		else
			ft_3dscene2(game, x, y, 0);
		return (0);
	}
	if (game->map[(int)(y + y2 / 20) / 50][(int)x / 50] == c)
	{
		y += y2 / 20;
		if (c == '1')
			ft_3dscene(game, x, y, 1);
		else
			ft_3dscene2(game, x, y, 1);
		return (0);
	}
	return (1);
}

void	ft_castray2(t_game *game, double x, double y)
{
	double	x2;
	double	y2;

	x2 = (cos(degtorad(game->r)) * 5);
	y2 = (sin(degtorad(game->r)) * 5);
	while (1)
	{
		if (!ft_wallordoor(game, x, y, '1'))
			return ;
		if (!ft_wallordoor(game, x, y, '2'))
			return ;
		x += x2 / 20;
		y += y2 / 20;
	}
}

void	ft_raycastwall(t_game *game, double x2, double y2)
{
	double	x;
	double	y;

	x = game->px;
	y = game->py;
	while (1)
	{
		if (game->map[(int)(y) / 50][(int)(x + x2 / 4) / 50] != '0'
			&& game->map[(int)(y) / 50][(int)(x + x2 / 4) / 50] != '3')
		{
			ft_castray2(game, x, y);
			return ;
		}
		else if (game->map[(int)(y + y2 / 4) / 50][(int)(x) / 50] != '0'
			&& game->map[(int)(y + y2 / 4) / 50][(int)(x) / 50] != '3')
		{
			ft_castray2(game, x, y);
			return ;
		}
		x += x2 / 4;
		y += y2 / 4;
	}
}
