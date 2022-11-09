/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:32:48 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/09 14:28:44 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		if ((game->r >= 0 && game->r <= 90.0)
			|| (game->r >= 270.0 && game->r <= 360.0))
			dst = game->we_texadr + (int)(i * (game->w_h / lineh))
				% game->w_h * game->llen[3]
				+ (int)(x * game->w_w / 50) % game->w_w * (game->bpp[3] / 8);
		if (game->r >= 90.0 && game->r <= 270.0)
			dst = game->ea_texadr + (int)(i * (game->e_h / lineh))
				% game->e_h * game->llen[4]
				+ (int)(x * game->e_w / 50) % game->e_w * (game->bpp[4] / 8);
		my_mlx_pixel_put(game, game->i, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}
