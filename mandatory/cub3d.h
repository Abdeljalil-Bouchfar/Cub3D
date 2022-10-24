/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:54:59 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/24 14:09:25 by ressalhi         ###   ########.fr       */
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


# define WIN_HIGHT 1080.0
# define WIN_WIDTH 1080.0

# define BUFFER_SIZE 1
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define N_W 1190
# define S_W 1162
# define W_W 1468
# define E_W 1000
	
# define P_SPEED 15

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
	float	*lineo;
	float	*lineh;
	int		i;
	int		*keys;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*no_tex;
	char	*no_texadr;
	int		bits_per_pixel1;
	int		line_length1;
	int		endian1;
	void	*so_tex;
	char	*so_texadr;
	int		bits_per_pixel2;
	int		line_length2;
	int		endian2;
	void	*we_tex;
	char	*we_texadr;
	int		bits_per_pixel3;
	int		line_length3;
	int		endian3;
	void	*ea_tex;
	char	*ea_texadr;
	int		bits_per_pixel4;
	int		line_length4;
	int		endian4;
	char	*no_textr;
	char	*so_textr;
	char	*we_textr;
	char	*ea_textr;
	int		floor_c;
	int		ceilling_c;
}		t_game;

void	parse(t_game *game, char *path);
void	ft_check_map(char *str, char *cub);

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char *s, char c);
char	*get_next_line(int fd);
void	ft_error(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	ft_drawl(t_game *game, double x2, double y2);
double	degtorad(double a);
double	dist(float ax, float ay, float bx, float by);
int		ft_hook(t_game *game);
void	ft_drawc(t_game *game, float y1);
void	ft_drawf(t_game *game, double lineh, float lineo, float x, float y);
void	ft_moveup(t_game *game);
void	ft_movedown(t_game *game);
void	ft_moveright(t_game *game);
void	ft_moveleft(t_game *game);
double	fixang(double a);
void	draw_rays(t_game *game);

#endif
