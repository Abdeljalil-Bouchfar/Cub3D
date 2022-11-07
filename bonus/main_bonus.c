/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:56:11 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/07 15:48:51 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_rays(t_game *g)
{
	double	x;
	double	y;

	g->r = fixang(g->pa - 30.0);
	g->i = 0;
	while (g->i < WIN_WIDTH)
	{
		x = cos(degtorad(g->r));
		y = sin(degtorad(g->r));
		ft_drawl(g, x, y);
		ft_sprite(g, x * 5, y * 5);
		g->i++;
		g->r += 60.0 / WIN_WIDTH;
		g->r = fixang(g->r);
	}
}

int	key_hook2(int keycode, t_game *g)
{
	if (keycode == UP)
		g->keys[0] = 0;
	else if (keycode == DOWN)
		g->keys[1] = 0;
	else if (keycode == RIGHT)
		g->keys[2] = 0;
	else if (keycode == LEFT)
		g->keys[3] = 0;
	else if (keycode == ROTATE_RIGHT)
		g->keys[4] = 0;
	else if (keycode == ROTATE_LEFT)
		g->keys[5] = 0;
	return (0);
}

int	key_hook1(int keycode, t_game *g)
{
	if (keycode == 53)
		ft_error("GAME CLOSED\n");
	else if (keycode == UP)
		g->keys[0] = 1;
	else if (keycode == DOWN)
		g->keys[1] = 1;
	else if (keycode == RIGHT)
		g->keys[2] = 1;
	else if (keycode == LEFT)
		g->keys[3] = 1;
	else if (keycode == ROTATE_RIGHT)
		g->keys[4] = 1;
	else if (keycode == ROTATE_LEFT)
		g->keys[5] = 1;
	else if (keycode == E)
		ft_opendoor(g);
	return (0);
}

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

char	*get_tex(int i)
{
	char	*s;

	s = ft_strdup("xpms/fire/fire1.xpm");
	s[14] = i + 48;
	return (s);
}

void	get_str_path(t_game *g)
{
	int	i;

	g->spritetex = malloc(sizeof(char *) * 9);
	i = 0;
	while (i < 8)
	{
		g->spritetex[i] = get_tex(i + 1);
		i++;
	}
	g->spritetex[i] = 0;
}

void	get_sprites(t_game *g)
{
	int	i;
	int	hi;

	get_str_path(g);
	g->sprite = malloc(sizeof(void *) * 8);
	g->spriteadr = malloc(sizeof(char *) * 9);
	i = 0;
	while (i < 8)
	{
		g->sprite[i] = mlx_xpm_file_to_image(g->mlx,
				g->spritetex[i], &hi, &hi);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		g->spriteadr[i] = mlx_get_data_addr(g->sprite[i],
				&g->bpp2[i], &g->ll2[i],
				&g->end2[i]);
		i++;
	}
	g->spriteadr[i] = 0;
}

void	ft_init(t_game *g)
{
	int	hi;

	g->keys = ft_calloc(sizeof(int), 6);
	g->bpp2 = ft_calloc(sizeof(int), 9);
	g->ll2 = ft_calloc(sizeof(int), 9);
	g->end2 = ft_calloc(sizeof(int), 9);
	g->img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HIGHT);
	g->addr = mlx_get_data_addr(g->img,
			&g->bpp, &g->ll, &g->end);
	get_player_cord(g);
	g->mousex = WIN_WIDTH / 2;
	g->index = 0;
	get_sprites(g);
	g->pdx = cos(degtorad(g->pa)) * (P_SPEED);
	g->pdy = sin(degtorad(g->pa)) * (P_SPEED);
	g->tex1 = mlx_xpm_file_to_image(g->mlx, "xpms/stone.xpm", &hi, &hi);
	g->tadr1 = mlx_get_data_addr(g->tex1, &g->bpp1, &g->ll1, &g->end1);
	g->door = mlx_xpm_file_to_image(g->mlx, "xpms/door.xpm", &hi, &hi);
	g->dooradr = mlx_get_data_addr(g->door, &g->bpp6, &g->ll6, &g->end6);
	draw_rays(g);
}

int	ft_hook(t_game *g)
{
	mlx_destroy_image(g->mlx, g->img);
	g->img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HIGHT);
	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->ll, &g->end);
	if (g->keys[0])
		ft_moveup(g);
	if (g->keys[1])
		ft_movedown(g);
	if (g->keys[2])
		ft_moveright(g);
	if (g->keys[3])
		ft_moveleft(g);
	if (g->keys[4])
		ft_rotateright(g);
	if (g->keys[5])
		ft_rotateleft(g);
	g->index++;
	if (g->index > 14)
		g->index = 0;
	draw_rays(g);
	// mini_map(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img, 0, 0);
	return (0);
}

int	key_hook3(int x, int y, t_game *g)
{
	if ((x > 0 && x < WIN_WIDTH) && (y > 0 && y < WIN_HIGHT))
	{
		if (g->mousex < x)
		{
			g->mousex = x;
			ft_rotateright(g);
		}
		else if (g->mousex > x)
		{
			g->mousex = x;
			ft_rotateleft(g);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*g;

	if (ac != 2)
		ft_error("Error\nWrong Number Of Args\n");
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
	mlx_loop_hook(g->mlx, ft_hook, g);
	mlx_loop(g->mlx);
}
