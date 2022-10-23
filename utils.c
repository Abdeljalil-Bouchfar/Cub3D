/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:32:48 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/22 16:07:12 by ressalhi         ###   ########.fr       */
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

	if ((x > 0 && x < (int)WIN_WIDTH) || (y > 0 && y < (int)WIN_HIGHT))
	{
		dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

double	fixang(double a)
{
	if (a > 360.0)
		a -= 360.0;
	if (a < 0)
		a += 360.0;
	return (a);
}

char	*get_bar(int i)
{
	char	*s;

	s = ft_strdup("bar/bar1.xpm");
	s[7] = i + 48;
	return (s);
}

void	creat_str_bar(t_game *game)
{
	int	i;

	game->bartex = malloc(sizeof(char *) * 10);
	i = 0;
	while (i < 9)
	{
		game->bartex[i] = get_bar(i + 1);
		i++;
	}
	game->bartex[i] = 0;
}
