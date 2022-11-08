/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawlines_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:42:13 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/08 15:42:37 by ressalhi         ###   ########.fr       */
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
			dst = game->no_texadr + (int)(i * (N_W / lineh)) % N_W * game->llen1
				+ (int)(x * N_W / 50) % N_W * (game->bpp1 / 8);
		if (game->r >= 0 && game->r <= 180.0)
			dst = game->so_texadr + (int)(i * (S_W / lineh)) % S_W * game->llen2
				+ (int)(x * S_W / 50) % S_W * (game->bpp2 / 8);
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
			dst = game->we_texadr + (int)(i * (W_W / lineh)) % W_W * game->llen3
				+ (int)(x * W_W / 50) % W_W * (game->bpp3 / 8);
		if (game->r >= 90.0 && game->r <= 270.0)
			dst = game->ea_texadr + (int)(i * (E_W / lineh)) % E_W * game->llen4
				+ (int)(x * E_W / 50) % E_W * (game->bpp4 / 8);
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
		dst = game->dooradr + (int)(i * (DOOR_W / lineh)) % DOOR_W * game->ll5
			+ (int)(x * DOOR_W / 50) % DOOR_W * (game->bpp5 / 8);
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
