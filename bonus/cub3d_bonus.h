/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:54:59 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/07 22:29:31 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define WIN_HIGHT 1080.0
# define WIN_WIDTH 1080.0

# define BUFFER_SIZE 1
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ROTATE_RIGHT 124
# define ROTATE_LEFT 123
# define E 14
# define N_W 1190
# define S_W 1162
# define W_W 1468
# define E_W 1000
# define DOOR_W 230
# define SP_W 256
# define P_SPEED 8
# define V 2

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	float	px;
	float	py;
	double	pdx;
	double	pdy;
	double	pa;
	double	r;
	double	length;
	double	xhit;
	double	yhit;
	int		i;
	int		index;
	int		*keys;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		end;
	void	*no_tex;
	char	*no_texadr;
	int		bpp1;
	int		llen1;
	int		en1;
	void	*so_tex;
	char	*so_texadr;
	int		bpp2;
	int		llen2;
	int		en2;
	void	*we_tex;
	char	*we_texadr;
	int		bpp3;
	int		llen3;
	int		en3;
	void	*ea_tex;
	char	*ea_texadr;
	int		bpp4;
	int		llen4;
	int		en4;
	char	**spritetex;
	void	**sprite;
	char	**spriteadr;
	int		*bpp6;
	int		*ll6;
	int		*end6;
	void	*spr;
	char	*spradr;
	void	*door;
	char	*dooradr;
	int		bpp5;
	int		ll5;
	int		end5;
	char	*no_textr;
	char	*so_textr;
	char	*we_textr;
	char	*ea_textr;
	int		floor_c;
	int		ceilling_c;
	int		mousex;
}		t_game;

// ----------------- Parse -------------------

void	parse(t_game *game, char *path);
int		check_line(t_game *game, char *line);

// ----------------- Shared -------------------

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char *s, char c);
char	*get_next_line(int fd);
void	ft_error(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

// ----------------- Graphics -------------------

void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	ft_raycast(t_game *game, double x2, double y2);
double	degtorad(double a);
double	dist(float ax, float ay, float bx, float by);
int		ft_hook(t_game *game);
void	ft_drawc(t_game *game, float y1);
void	ft_drawf(t_game *game, double lineh, float lineo);
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
void	ft_rotateright(t_game *game);
void	ft_rotateleft(t_game *game);
void	ft_drawline1(t_game *game, float y1, double lineh, float x);
void	ft_drawline2(t_game *game, float y1, double lineh, float x);
void	ft_drawline3(t_game *game, float y1, double lineh, float x);
void	ft_drawline4(t_game *game, float y1, double lineh, float x);
void	ft_3dsprite(t_game *game, double x, double y, int i);
void	ft_sprite2(t_game *game, double x, double y);
void	ft_sprite(t_game *game, double x2, double y2);
void	ft_3dscene2(t_game *game, float x, float y, int i);
void	mini_map(t_game *g);

#endif
