/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:42:13 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/09 14:58:40 by ressalhi         ###   ########.fr       */
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
			dst = game->no_texadr + (int)(i * (game->n_h / lineh))
				% game->n_h * game->llen[1]
				+ (int)(x * game->n_w / 50) % game->n_w * (game->bpp[1] / 8);
		if (game->r >= 0 && game->r <= 180.0)
			dst = game->so_texadr + (int)(i * (game->s_h / lineh))
				% game->s_h * game->llen[2]
				+ (int)(x * game->s_w / 50) % game->s_w * (game->bpp[2] / 8);
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
		dst = game->dooradr + (int)(i * (game->d_h / lineh))
			% game->d_h * game->llen[5]
			+ (int)(x * game->d_w / 50) % game->d_w * (game->bpp[5] / 8);
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
