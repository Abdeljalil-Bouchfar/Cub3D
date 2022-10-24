/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:13:39 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/24 14:09:55 by ressalhi         ###   ########.fr       */
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
		dst = game->we_texadr + (int)(i * (W_W / lineh)) % W_W * game->line_length3 + (int)(x * W_W / 50) % W_W * (game->bits_per_pixel3 / 8);
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
		my_mlx_pixel_put(game, game->i, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}

void	ft_drawf(t_game *game, double lineh, float lineo, float x, float y)
{
	int		j;
	(void)x;
	(void)y;

	j = (int)(lineh + lineo);
	while (j < WIN_HIGHT)
	{
		my_mlx_pixel_put(game, game->i, j, game->floor_c);
		j++;
	}
}

void	ft_drawc(t_game *game, float y1)
{
	int	i;
	
	i = 0;
	while (i < WIN_HIGHT)
	{
		y1 = 0;
		while (y1 < game->lineo[i])
		{
			my_mlx_pixel_put(game, i, y1, game->ceilling_c);
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
