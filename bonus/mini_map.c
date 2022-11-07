/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:39:09 by abouchfa          #+#    #+#             */
/*   Updated: 2022/11/07 12:11:18 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_player(t_game *game, float x, float y)
{
	float	xi;
	float	yi;

	yi = -5;
	while (yi < 5)
	{
		xi = -5;
		while (xi < 5)
		{
			if (dist(120, 120, x + xi, y + yi) <= 5.0)
				my_mlx_pixel_put(game, xi + x, yi + y, 0x000000);
			xi += 0.1;
		}
		yi += 0.1;
	}
	yi = 10;
	while (yi--)
	{
		my_mlx_pixel_put(game, x, y, 0xFFFFFF);;
		x += cos(degtorad(game->pa));
		y += sin(degtorad(game->pa));
	}
}

void	mini_map(t_game *g)
{
	int	l;
	int	xi;
	int	yi;
	int	x;
	int	y;

	l = 0;
	xi = (g->px / 50) * 20 - 120;
	yi = (g->py / 50) * 20 - 120;
	while (g->map[l])
		l++;
	y = 0;
	while (y < 220)
	{
		x = 0;
		while (x < 220)
		{
			if (dist(120, 120, x, y) <= 100)
			{
				if (xi + x >= 0 && yi + y >= 0
					&& l > ((y + yi) / 20) && g->map[((y + yi) / 20)]
					&& ft_strlen(g->map[((y + yi) / 20)]) > ((x + xi) / 20)
					&& g->map[((y + yi) / 20)][((x + xi) / 20)] != '1')
					{
						if (g->map[((y + yi) / 20)][((x + xi) / 20)] == '2')
							my_mlx_pixel_put(g, x, y, 0xFFFF00);
						else if (g->map[((y + yi) / 20)][((x + xi) / 20)] == '4')
							my_mlx_pixel_put(g, x, y, 0xFF0000);
						else
							my_mlx_pixel_put(g, x, y, 0x0A8500);
					}
				else
					my_mlx_pixel_put(g, x, y, 0x808080);
			}
			x++;
		}
		y++;
	}
	draw_player(g, 120.0f, 120.0f);
}