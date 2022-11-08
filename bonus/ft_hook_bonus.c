/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:38:03 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/08 15:39:52 by ressalhi         ###   ########.fr       */
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
		ft_raycastwall(g, x, y);
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
	draw_rays(g);
	mini_map(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img, 0, 0);
	return (0);
}
