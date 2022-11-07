/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:27:12 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/07 15:54:22 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_moveup(t_game *g)
{
	int	xo;
	int	yo;

	if (g->pdx < 0)
		xo = -30;
	else
		xo = 30;
	if (g->pdy < 0)
		yo = -30;
	else
		yo = 30;
	if (g->map[(int)(g->py / 50)][(int)((g->px + xo) / 50)] == '0'
		|| g->map[(int)(g->py / 50)][(int)((g->px + xo) / 50)] == '3')
		g->px += g->pdx;
	if (g->map[(int)((g->py + yo) / 50)][(int)(g->px / 50)] == '0'
		|| g->map[(int)((g->py + yo) / 50)][(int)(g->px / 50)] == '3')
		g->py += g->pdy;
	else if (g->map[(int)((g->py + yo) / 50)][(int)((g->px + xo) / 50)] == '4')
		ft_error("YOU DIE\n");
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
	if (g->map[(int)(g->py / 50)][(int)((g->px - xo) / 50)] == '0'
		|| g->map[(int)(g->py / 50)][(int)((g->px - xo) / 50)] == '3')
		g->px -= g->pdx;
	if (g->map[(int)((g->py - yo) / 50)][(int)(g->px / 50)] == '0'
		|| g->map[(int)((g->py - yo) / 50)][(int)(g->px / 50)] == '3')
		g->py -= g->pdy;
	else if (g->map[(int)((g->py - yo) / 50)][(int)((g->px - xo) / 50)] == '4')
		ft_error("YOU DIE\n");
}

void	ft_rotateright(t_game *g)
{
	g->pa += 3;
	if (g->pa > 360)
		g->pa -= 360;
	g->pdx = cos(degtorad(g->pa)) * P_SPEED;
	g->pdy = sin(degtorad(g->pa)) * P_SPEED;
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
	if (g->map[(int)((g->py + yo) / 50)][(int)((g->px + xo) / 50)] == '0')
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
	if (g->map[(int)((g->py + yo) / 50)][(int)((g->px + xo) / 50)] == '0')
	{
		g->px += nadx;
		g->py += nady;
	}
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
