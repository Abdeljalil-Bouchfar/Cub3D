/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:27:12 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/24 20:44:07 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_moveup(t_game *game)
{
	int	xo;
	int	yo;

	if (game->pdx < 0)
		xo = -30;
	else
		xo = 30;
	if (game->pdy < 0)
		yo = -30;
	else
		yo = 30;
	if (game->map[(int)(game->py / 50.0)][(int)((game->px + xo) / 50.0)] == '0')
		game->px += game->pdx;
	if (game->map[(int)((game->py + yo) / 50.0)][(int)(game->px / 50.0)] == '0')
		game->py += game->pdy;
}

void	ft_movedown(t_game *game)
{
	int	xo;
	int	yo;

	if (game->pdx < 0)
		xo = -20;
	else
		xo = 20;
	if (game->pdy < 0)
		yo = -20;
	else
		yo = 20;
	if (game->map[(int)(game->py / 50.0)][(int)((game->px - xo) / 50.0)] == '0')
		game->px -= game->pdx;
	if (game->map[(int)((game->py - yo) / 50.0)][(int)(game->px / 50.0)] == '0')
		game->py -= game->pdy;
}

void	ft_moveright(t_game *game)
{
	game->pa += 3;
	if (game->pa > 360)
		game->pa -= 360;
	game->pdx = cos(degtorad(game->pa)) * P_SPEED;
	game->pdy = sin(degtorad(game->pa)) * P_SPEED;
}

void	ft_moveleft(t_game *game)
{
	game->pa -= 3;
	if (game->pa < 0)
		game->pa += 360;
	game->pdx = cos(degtorad(game->pa)) * P_SPEED;
	game->pdy = sin(degtorad(game->pa)) * P_SPEED;
}
