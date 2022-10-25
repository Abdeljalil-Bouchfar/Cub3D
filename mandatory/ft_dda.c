/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:13:39 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/24 20:45:01 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_drawfloor(t_game *game, double lineh, float lineo)
{
	int		j;

	j = (int)(lineh + lineo);
	while (j < WIN_HIGHT)
	{
		my_mlx_pixel_put(game, game->i, j, game->floor_c);
		j++;
	}
}

void	ft_drawceilling(t_game *game, float lineo)
{
	int	i;

	i = 0;
	while (i < lineo)
	{
		my_mlx_pixel_put(game, game->i, i, game->ceilling_c);
		i++;
	}
}

void	ft_3dscene(t_game *game, float x, float y, int i)
{
	double	lineh;
	double	ch;
	double	len;
	float	lineo;
	double	ca;

	ca = game->pa - game->r;
	ca = fixang(ca);
	len = dist(game->px, game->py, x, y);
	len = len * cos(degtorad(ca));
	lineh = (50 * WIN_HIGHT) / len;
	ch = lineh;
	if (lineh > WIN_HIGHT)
		lineh = WIN_HIGHT;
	lineo = (WIN_HIGHT / 2.0) - (lineh / 2.0);
	if (i == 1)
		ft_drawline3(game, lineo, ch, x);
	else
		ft_drawline4(game, lineo, ch, y);
	ft_drawfloor(game, lineh, lineo);
	ft_drawceilling(game, lineo);
}

void	ft_castray2(t_game *game, double x, double y)
{
	double	x2;
	double	y2;

	x2 = (cos(degtorad(game->r)) * 5);
	y2 = (sin(degtorad(game->r)) * 5);
	while (1)
	{
		if (game->map[(int)y / 50][(int)(x + x2 / 64) / 50] == '1')
		{
			x += x2 / 64;
			ft_3dscene(game, x, y, 0);
			return ;
		}
		if (game->map[(int)(y + y2 / 64) / 50][(int)x / 50] == '1')
		{
			y += y2 / 64;
			ft_3dscene(game, x, y, 1);
			return ;
		}
		x += x2 / 64;
		y += y2 / 64;
	}
}

void	ft_castray1(t_game *game, double x2, double y2)
{
	double	x;
	double	y;

	x = game->px;
	y = game->py;
	while (1)
	{
		if (game->map[(int)(y + y2) / 50][(int)(x + x2) / 50] != '0')
		{
			ft_castray2(game, x, y);
			return ;
		}
		x += x2;
		y += y2;
	}
}
