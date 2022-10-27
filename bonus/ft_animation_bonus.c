/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:24:34 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/27 15:26:19 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_anime(t_game *game)
{
	int	p;
	static int	i;
	if (i == 1 * V)
	{
        mlx_destroy_image(game->mlx, game->hand);
		game->hand = mlx_xpm_file_to_image(game->mlx, "xpms/hand/hand1.xpm", &p, &p);
	}
	// if (i == 2 * V)
	// {
    //     mlx_destroy_image(game->mlx, game->hand);
	// 	game->hand = mlx_xpm_file_to_image(game->mlx, "xpms/hand/hand2.xpm", &p, &p);
	// }
	if (i == 2 * V)
	{
        mlx_destroy_image(game->mlx, game->hand);
		game->hand = mlx_xpm_file_to_image(game->mlx, "xpms/hand/hand3.xpm", &p, &p);
	}
    if (i == 3 * V)
	{
        mlx_destroy_image(game->mlx, game->hand);
		game->hand = mlx_xpm_file_to_image(game->mlx, "xpms/hand/hand4.xpm", &p, &p);
	}
	if (i == 4 * V)
	{
        mlx_destroy_image(game->mlx, game->hand);
		game->hand = mlx_xpm_file_to_image(game->mlx, "xpms/hand/hand5.xpm", &p, &p);
	}
	if (i == 5 * V)
	{
        mlx_destroy_image(game->mlx, game->hand);
		game->hand = mlx_xpm_file_to_image(game->mlx, "xpms/hand/hand6.xpm", &p, &p);
	}
    if (i == 6 * V)
	{
		i = 0;
        mlx_destroy_image(game->mlx, game->hand);
		game->hand = mlx_xpm_file_to_image(game->mlx, "xpms/hand/hand7.xpm", &p, &p);
	}
	i++;
}
