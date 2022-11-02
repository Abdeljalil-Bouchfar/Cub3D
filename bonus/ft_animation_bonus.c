/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:24:34 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/02 15:48:51 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_anime(t_game *game)
{
	int	p;
	static int	i;
	if (i == 1 * V)
	{
        mlx_destroy_image(game->mlx, game->sprite);
		game->sprite = mlx_xpm_file_to_image(game->mlx, "xpms/fire/fire1.xpm", &p, &p);
	    game->spriteadr = mlx_get_data_addr(game->sprite, &game->bits_per_pixel2, &game->line_length2, &game->endian2);
	}
	if (i == 2 * V)
	{
        mlx_destroy_image(game->mlx, game->sprite);
		game->sprite = mlx_xpm_file_to_image(game->mlx, "xpms/fire/fire2.xpm", &p, &p);
        game->spriteadr = mlx_get_data_addr(game->sprite, &game->bits_per_pixel2, &game->line_length2, &game->endian2);
	}
    if (i == 3 * V)
	{
        mlx_destroy_image(game->mlx, game->sprite);
		game->sprite = mlx_xpm_file_to_image(game->mlx, "xpms/fire/fire3.xpm", &p, &p);
        game->spriteadr = mlx_get_data_addr(game->sprite, &game->bits_per_pixel2, &game->line_length2, &game->endian2);
	}
	if (i == 4 * V)
	{
        mlx_destroy_image(game->mlx, game->sprite);
		game->sprite = mlx_xpm_file_to_image(game->mlx, "xpms/fire/fire4.xpm", &p, &p);
        game->spriteadr = mlx_get_data_addr(game->sprite, &game->bits_per_pixel2, &game->line_length2, &game->endian2);
	}
	if (i == 5 * V)
	{
        mlx_destroy_image(game->mlx, game->sprite);
		game->sprite = mlx_xpm_file_to_image(game->mlx, "xpms/fire/fire5.xpm", &p, &p);
        game->spriteadr = mlx_get_data_addr(game->sprite, &game->bits_per_pixel2, &game->line_length2, &game->endian2);
	}
    if (i == 6 * V)
	{
        mlx_destroy_image(game->mlx, game->sprite);
		game->sprite = mlx_xpm_file_to_image(game->mlx, "xpms/fire/fire6.xpm", &p, &p);
        game->spriteadr = mlx_get_data_addr(game->sprite, &game->bits_per_pixel2, &game->line_length2, &game->endian2);
	}
	if (i == 7 * V)
	{
        mlx_destroy_image(game->mlx, game->sprite);
		game->sprite = mlx_xpm_file_to_image(game->mlx, "xpms/fire/fire7.xpm", &p, &p);
        game->spriteadr = mlx_get_data_addr(game->sprite, &game->bits_per_pixel2, &game->line_length2, &game->endian2);
	}
    if (i == 8 * V)
	{
        i = 0;
        mlx_destroy_image(game->mlx, game->sprite);
		game->sprite = mlx_xpm_file_to_image(game->mlx, "xpms/fire/fire8.xpm", &p, &p);
        game->spriteadr = mlx_get_data_addr(game->sprite, &game->bits_per_pixel2, &game->line_length2, &game->endian2);
	}
	i++;
}