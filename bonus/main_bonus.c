/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:56:11 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/08 18:28:50 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_player_angle(t_game *g, char c)
{
	if (c == 'N')
		g->pa = 270.0;
	else if (c == 'S')
		g->pa = 90.0;
	else if (c == 'W')
		g->pa = 180.0;
	else if (c == 'E')
		g->pa = 0;
}

void	get_player_cord(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'N' || g->map[i][j] == 'S' ||
				g->map[i][j] == 'E' || g->map[i][j] == 'W')
			{
				g->px = j * 51.5;
				g->py = i * 51.5;
				get_player_angle(g, g->map[i][j]);
				g->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	get_img_path(t_game *g)
{
	int	hi;

	g->no_tex = mlx_xpm_file_to_image(g->mlx, g->no_textr, &hi, &hi);
	if (!g->no_tex)
		ft_error("wrong texture path!!\n(north texture)\n");
	g->we_tex = mlx_xpm_file_to_image(g->mlx, g->we_textr, &hi, &hi);
	if (!g->we_tex)
		ft_error("wrong texture path!!\n(west texture)\n");
	g->so_tex = mlx_xpm_file_to_image(g->mlx, g->so_textr, &hi, &hi);
	if (!g->so_tex)
		ft_error("wrong texture path!!\n(south texture)\n");
	g->ea_tex = mlx_xpm_file_to_image(g->mlx, g->ea_textr, &hi, &hi);
	if (!g->ea_tex)
		ft_error("wrong texture path!!\n(east texture)\n");
	g->no_texadr = mlx_get_data_addr(g->no_tex, &g->bpp1, &g->llen1, &g->en1);
	g->so_texadr = mlx_get_data_addr(g->so_tex, &g->bpp2, &g->llen2, &g->en2);
	g->we_texadr = mlx_get_data_addr(g->we_tex, &g->bpp3, &g->llen3, &g->en3);
	g->ea_texadr = mlx_get_data_addr(g->ea_tex, &g->bpp4, &g->llen4, &g->en4);
	g->door = mlx_xpm_file_to_image(g->mlx, "xpms/door.xpm", &hi, &hi);
	if (!g->door)
		ft_error("wrong door texture path!!\n");
	g->dooradr = mlx_get_data_addr(g->door, &g->bpp5, &g->ll5, &g->end5);
}

void	ft_init(t_game *g)
{
	g->keys = ft_calloc(sizeof(int), 6);
	g->img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HIGHT);
	g->addr = mlx_get_data_addr(g->img,
			&g->bpp, &g->ll, &g->end);
	get_img_path(g);
	get_player_cord(g);
	g->mousex = WIN_WIDTH / 2;
	g->pdx = cos(degtorad(g->pa)) * (P_SPEED);
	g->pdy = sin(degtorad(g->pa)) * (P_SPEED);
	draw_rays(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_game	*g;

	if (ac != 2)
		ft_error("Error\nWrong Number Of Args\n");
	g_allocs = malloc(sizeof(t_allocs *));
	*g_allocs = NULL;
	g = malloc(sizeof(t_game));
	g->mlx = mlx_init();
	g->mlx_win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HIGHT, "cub3d");
	g->floor_c = -1;
	g->ceilling_c = -1;
	g->no_textr = NULL;
	g->so_textr = NULL;
	g->we_textr = NULL;
	g->ea_textr = NULL;
	parse(g, av[1]);
	ft_init(g);
	mlx_hook(g->mlx_win, 2, 1L << 0, key_hook1, g);
	mlx_hook(g->mlx_win, 3, 1L << 1, key_hook2, g);
	mlx_hook(g->mlx_win, 6, 1L << 2, key_hook3, g);
	mlx_hook(g->mlx_win, 17, 0, red_cross, NULL);
	mlx_loop_hook(g->mlx, ft_hook, g);
	mlx_loop(g->mlx);
}
