/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:32:48 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/09 14:47:51 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	dist(float ax, float ay, float bx, float by)
{
	return (sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay))));
}

double	degtorad(double a)
{
	return (a * M_PI / 180.0);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->llen[0] + x * (game->bpp[0] / 8));
	*(unsigned int *)dst = color;
}

double	fixang(double a)
{
	if (a > 360.0)
		a -= 360.0;
	if (a < 0)
		a += 360.0;
	return (a);
}

void	ft_opendoor(t_game *g)
{
	int	xo;
	int	yo;

	if (g->pdx < 0)
		xo = -50;
	else
		xo = 50;
	if (g->pdy < 0)
		yo = -50;
	else
		yo = 50;
	if (g->map[(int)(g->py / 50)][(int)((g->px + xo) / 50)] == '3')
		g->map[(int)(g->py / 50)][(int)((g->px + xo) / 50)] = '2';
	else if (g->map[(int)(g->py / 50)][(int)((g->px + xo) / 50)] == '2')
		g->map[(int)(g->py / 50)][(int)((g->px + xo) / 50)] = '3';
	else if (g->map[(int)((g->py + yo) / 50)][(int)(g->px / 50)] == '3')
		g->map[(int)((g->py + yo) / 50)][(int)(g->px / 50)] = '2';
	else if (g->map[(int)((g->py + yo) / 50)][(int)(g->px / 50)] == '2')
		g->map[(int)((g->py + yo) / 50)][(int)(g->px / 50)] = '3';
}
