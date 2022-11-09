/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:11:53 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/09 14:38:55 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_drawline3(t_game *g, float y1, double lineh, float x)
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
		if (g->r >= 180.0 && g->r <= 360.0)
			dst = g->no_texadr + (int)(i * (g->n_h / lineh))
				% g->n_h * g->llen[1]
				+ (int)(x * g->n_w / 50) % g->n_w * (g->bpp[1] / 8);
		if (g->r >= 0 && g->r <= 180.0)
			dst = g->so_texadr + (int)(i * (g->s_h / lineh))
				% g->s_h * g->llen[2]
				+ (int)(x * g->s_w / 50) % g->s_w * (g->bpp[2] / 8);
		my_mlx_pixel_put(g, g->i, y1, *(unsigned int *)dst);
		y1++;
		i++;
	}
}

void	draw_rays(t_game *g)
{
	double	x;
	double	y;

	g->r = fixang(g->pa - 30.0);
	g->i = 0;
	while (g->i < WIN_WIDTH)
	{
		x = (cos(degtorad(g->r)) * 5);
		y = (sin(degtorad(g->r)) * 5);
		ft_castray1(g, x, y);
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
	return (0);
}

int	ft_hook(t_game *g)
{
	mlx_destroy_image(g->mlx, g->img);
	g->img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HIGHT);
	g->addr = mlx_get_data_addr(g->img, &g->bpp[0],
			&g->llen[0], &g->en[0]);
	if (g->keys[0])
		ft_moveup(g);
	if (g->keys[1])
		ft_movedown(g);
	if (g->keys[4])
		ft_rotateright(g);
	if (g->keys[5])
		ft_rotateleft(g);
	if (g->keys[2])
		ft_moveright(g);
	if (g->keys[3])
		ft_moveleft(g);
	draw_rays(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img, 0, 0);
	return (0);
}
