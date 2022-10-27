/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:13:39 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/27 15:26:27 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		dst = game->tadr1 + (int)(i * (IMG_W1 / lineh)) % IMG_W1 * game->line_length1 + (int)(x * IMG_W1 / 50) % IMG_W1 * (game->bits_per_pixel1 / 8);
		my_mlx_pixel_put(game, game->i, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}

void	ft_drawline4(t_game *game, float y1, double lineh, float x)
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
		dst = game->dooradr + (int)(i * (DOOR_W / lineh)) % DOOR_W * game->line_length6 + (int)(x * DOOR_W / 50) % DOOR_W * (game->bits_per_pixel6/ 8);
		my_mlx_pixel_put(game, game->i, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}

void	ft_drawf(t_game *game, double lineh, float lineo, float x, float y)
{
	char	*dst;
	float	dy, tx, ty, deg, rafix;
	int		j,l;
	(void)x;
	(void)y;

	j = (int)(lineh + lineo);
	l=0;
	deg = degtorad(game->r);
	rafix = cos(degtorad(fixang(game->pa-game->r)));
	while (j < WIN_HIGHT)
	{
		dy = j-(WIN_HIGHT/2.0);
		tx = game->px*20 + (cos(deg)*(WIN_HIGHT/2)*FLOOR_W/dy/rafix);
		ty = game->py*20 + (sin(deg)*(WIN_HIGHT/2)*FLOOR_W/dy/rafix);
		int y;
		int x;
		y = ((int)(ty)%FLOOR_W);
		// printf("%d\n", y);
		if (y < 0)
			y *= -1;
		x = ((int)(tx)%FLOOR_W);
		if (x < 0)
			x *= -1;
		dst = game->flooradr + (y * game->line_length7 + x * (game->bits_per_pixel7 / 8));
		my_mlx_pixel_put(game, game->i, j, *(unsigned int *)dst);
		// my_mlx_pixel_put(game, game->i, 1080-j, *(unsigned int *)dst);
		j++;
		l++;
	}
}

void	ft_drawc(t_game *game, float y1)
{
	char *dst;
	int	i;
	
	i = 0;
	while (i < WIN_HIGHT)
	{
		y1 = 0;
		while (y1 < game->lineo[i])
		{
			dst = game->skyadr + (int)(y1+100) * game->line_length5 + (int)(i+game->pix) * (game->bits_per_pixel5 / 8);
			my_mlx_pixel_put(game, i, y1, *(unsigned int *)dst);
			y1++;
		}
		i++;
	}
}

void	ft_3dscene(t_game *game, float x, float y, int i)
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
	game->lineh[game->i] = lineh;
	lineo = (WIN_HIGHT/2.0) - (lineh / 2.0);
	// lineo += game->offset;
	game->lineo[game->i] = lineo;
	if (i == 1)
		ft_drawline3(game, lineo, ch, x);
	else
		ft_drawline3(game, lineo, ch, y);
	ft_drawf(game, lineh, lineo, x, y);
}

void	ft_3dscene2(t_game *game, float x, float y, int i)
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
	game->lineh[game->i] = lineh;
	lineo = (WIN_HIGHT/2) - (lineh / 2);
	// lineo += game->offset;
	game->lineo[game->i] = lineo;
	if (i == 1)
		ft_drawline4(game, lineo, ch, x);
	else
		ft_drawline4(game, lineo, ch, y);
	ft_drawf(game, lineh, lineo, x, y);
}

void	ft_drawl(t_game *game, double x2, double y2)
{
	double	x;
	double	y;

	x = game->px;
	y = game->py;
	while (1)
	{
		if (game->map[(int)(y + y2) / 50][(int)(x + x2) / 50] != '0' && game->map[(int)(y + y2) / 50][(int)(x + x2) / 50] != '3')
		{
			while (1)
			{
				if (game->map[(int)y / 50][(int)(x + x2 / 64) / 50] == '1')
				{
					x += x2 / 64;
					ft_3dscene(game, x, y, 0);
					return ;
				}
				else if (game->map[(int)y / 50][(int)(x + x2 / 64) / 50] == '2')
				{
					x += x2 / 64;
					ft_3dscene2(game, x, y, 0);
					return ;
				}
				if (game->map[(int)(y + y2 / 64) / 50][(int)x / 50] == '1')
				{
					y += y2 / 64;
					ft_3dscene(game, x, y, 1);
					return ;
				}
				else if (game->map[(int)(y + y2 / 64) / 50][(int)x / 50] == '2')
				{
					y += y2 / 64;
					ft_3dscene2(game, x, y, 1);
					return ;
				}
				x += x2 / 64;
				y += y2 / 64;
			}
		}
		x += x2;
		y += y2;
	}
}
