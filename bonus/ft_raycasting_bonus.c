/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:13:39 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/07 22:02:12 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_drawline1(t_game *game, float y1, double lineh, float x)
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
		my_mlx_pixel_put(game, game->i, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}

void	ft_drawline2(t_game *game, float y1, double lineh, float x)
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
		if ((game->r >= 0 && game->r <= 90.0)
			|| (game->r >= 270.0 && game->r <= 360.0))
			dst = game->we_texadr + (int)(i * (W_W / lineh)) % W_W * game->llen3
				+ (int)(x * W_W / 50) % W_W * (game->bpp3 / 8);
		if (game->r >= 90.0 && game->r <= 270.0)
			dst = game->ea_texadr + (int)(i * (E_W / lineh)) % E_W * game->llen4
				+ (int)(x * E_W / 50) % E_W * (game->bpp4 / 8);
		my_mlx_pixel_put(game, game->i, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}

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
		dst = game->dooradr + (int)(i * (DOOR_W / lineh)) % DOOR_W * game->ll5
			+ (int)(x * DOOR_W / 50) % DOOR_W * (game->bpp5 / 8);
		if (*(unsigned int *)dst != 0xFF000000)
			my_mlx_pixel_put(game, game->i, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}

void	ft_drawf(t_game *game, double lineh, float lineo)
{
	int		j;

	j = (int)(lineh + lineo);
	while (j < WIN_HIGHT)
	{
		my_mlx_pixel_put(game, game->i, j, 0x0A8500);
		j++;
	}
}

void	ft_drawc(t_game *game, float lineo)
{
	int	i;

	i = 0;
	while (i < lineo)
	{
		my_mlx_pixel_put(game, game->i, i, 0x0BFBE9);
		i++;
	}
}

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

void	ft_raycast(t_game *game, double x2, double y2)
{
	double	x;
	double	y;

	x = game->px;
	y = game->py;
	while (1)
	{
		if (game->map[(int)(y) / 50][(int)(x + x2 / 4) / 50] != '0'
			&& game->map[(int)(y) / 50][(int)(x + x2 / 4) / 50] != '3'
			&& game->map[(int)(y) / 50][(int)(x + x2 / 4) / 50] != '4')
		{
			ft_castray2(game, x, y);
			return ;
		}
		else if (game->map[(int)(y + y2 / 4) / 50][(int)(x) / 50] != '0'
			&& game->map[(int)(y + y2 / 4) / 50][(int)(x) / 50] != '3'
			&& game->map[(int)(y + y2 / 4) / 50][(int)(x) / 50] != '4')
		{
			ft_castray2(game, x, y);
			return ;
		}
		x += x2 / 4;
		y += y2 / 4;
	}
}
