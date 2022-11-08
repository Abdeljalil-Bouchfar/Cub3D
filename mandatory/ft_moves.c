/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:27:12 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/08 20:02:06 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_moveup(t_game *g)
{
	int	xo;
	int	yo;

	if (g->pdx < 0)
		xo = -20;
	else
		xo = 20;
	if (g->pdy < 0)
		yo = -20;
	else
		yo = 20;
	if (g->map[(int)((g->py + yo) / 50.0)][(int)((g->px + xo) / 50.0)] == '1'
		&& g->map[(int)(g->py / 50.0)][(int)((g->px + xo) / 50.0)] == '0'
		&& g->map[(int)((g->py + yo) / 50.0)][(int)(g->px / 50.0)] == '0')
		return ;
	if (g->map[(int)(g->py / 50.0)][(int)((g->px + xo) / 50.0)] == '0')
		g->px += g->pdx;
	if (g->map[(int)((g->py + yo) / 50.0)][(int)(g->px / 50.0)] == '0')
		g->py += g->pdy;
}

void	ft_movedown(t_game *g)
{
	int	xo;
	int	yo;

	if (g->pdx < 0)
		xo = -20;
	else
		xo = 20;
	if (g->pdy < 0)
		yo = -20;
	else
		yo = 20;
	if (g->map[(int)(g->py / 50.0)][(int)((g->px - xo) / 50.0)] == '0')
		g->px -= g->pdx;
	if (g->map[(int)((g->py - yo) / 50.0)][(int)(g->px / 50.0)] == '0')
		g->py -= g->pdy;
}

void	ft_rotateleft(t_game *g)
{
	g->pa -= 3;
	if (g->pa < 0)
		g->pa += 360;
	g->pdx = cos(degtorad(g->pa)) * P_SPEED;
	g->pdy = sin(degtorad(g->pa)) * P_SPEED;
}

void	ft_moveright(t_game *g)
{
	int		xo;
	int		yo;
	double	nadx;
	double	nady;
	double	na;

	na = fixang(g->pa + 90.0);
	nadx = cos(degtorad(na)) * P_SPEED;
	nady = sin(degtorad(na)) * P_SPEED;
	if (nadx < 0)
		xo = -20;
	else
		xo = 20;
	if (nady < 0)
		yo = -20;
	else
		yo = 20;
	if (g->map[(int)((g->py + yo) / 50.0)][(int)((g->px + xo) / 50.0)] == '0')
	{
		g->px += nadx;
		g->py += nady;
	}
}

void	ft_moveleft(t_game *g)
{
	int		xo;
	int		yo;
	double	nadx;
	double	nady;
	double	na;

	na = fixang(g->pa - 90.0);
	nadx = cos(degtorad(na)) * P_SPEED;
	nady = sin(degtorad(na)) * P_SPEED;
	if (nadx < 0)
		xo = -20;
	else
		xo = 20;
	if (nady < 0)
		yo = -20;
	else
		yo = 20;
	if (g->map[(int)((g->py + yo) / 50.0)][(int)((g->px + xo) / 50.0)] == '0')
	{
		g->px += nadx;
		g->py += nady;
	}
}
