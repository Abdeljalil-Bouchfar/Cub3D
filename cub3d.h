/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeljalilbouchfar <abdeljalilbouchfar@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:54:59 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/21 11:42:41 by abdeljalilb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define BUFFER_SIZE 1
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define E 14
# define SPACE 49
# define IMG_W1 826
# define DOOR_W 230
# define FLOOR_W 890
# define V 1
# define P_SPEED 10
# define W 13
# define Q 12
# define X 7

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**bartex;
	int		barn;
	float	px;
	float	py;
	double	pdx;
	double	pdy;
	double	pa;
	double	r;
	float	*lineo;
	int		offset;
	int		cpa;
	float	*lineh;
	int		i;
	int		*keys;
	float	pix;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*tex1;
	char	*tadr1;
	int		bits_per_pixel1;
	int		line_length1;
	int		endian1;
	void	*sky;
	char	*skyadr;
	int		bits_per_pixel5;
	int		line_length5;
	int		endian5;
	void	*door;
	char	*dooradr;
	int		bits_per_pixel6;
	int		line_length6;
	int		endian6;
	void	*door2;
	char	*door2adr;
	int		bits_per_pixel8;
	int		line_length8;
	int		endian8;
	void	*floor;
	char	*flooradr;
	int		bits_per_pixel7;
	int		line_length7;
	int		endian7;
	void	*bar;
	void	*hand;
	char	*handadr;
	char	*no_textr;
	char	*so_textr;
	char	*we_textr;
	char	*ea_textr;
	int		floor_c;
	int		ceilling_c;
}		t_game;

void	parse(t_game *game, char *path);
void	ft_check_map(char *str, char *cub);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strchr(char *s, char c);
char	**ft_split(char *s, char c);
char	*get_next_line(int fd);
void	ft_error(char *str);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	ft_drawl(t_game *game, double x2, double y2);
double	degtorad(double a);
double	dist(float ax, float ay, float bx, float by);
int		ft_hook(t_game *game);
void	ft_drawc(t_game *game, float y1);
void	ft_drawf(t_game *game, double lineh, float lineo, float x, float y);
void	ft_cloud(t_game *game);
void	ft_moveup(t_game *game);
void	ft_movedown(t_game *game);
void	ft_moveright(t_game *game);
void	ft_moveleft(t_game *game);
void	ft_animation(t_game *game);
void	ft_opendoor(t_game *game);
double	fixang(double a);
void	ft_anime(t_game *game);
void	draw_rays(t_game *game);
void	ft_build(t_game *game);
void	ft_destroy(t_game *game);
void	creat_str_bar(t_game *game);

#endif
