/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:54:59 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/14 11:51:30 by ressalhi         ###   ########.fr       */
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
# define WIN_WIDTH 1340.0

# define BUFFER_SIZE 1
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ROTATE_RIGHT 124
# define ROTATE_LEFT 123
# define P_SPEED 8

typedef struct s_allocs
{
	void			*content;
	struct s_allocs	*next;
}	t_allocs;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**map_dup;
	float	px;
	float	py;
	double	pdx;
	double	pdy;
	double	pa;
	double	r;
	int		i;
	int		*keys;
	void	*img;
	char	*addr;
	int		*bpp;
	int		*llen;
	int		*en;
	void	*no_tex;
	char	*no_texadr;
	int		n_w;
	int		n_h;
	void	*so_tex;
	char	*so_texadr;
	int		s_w;
	int		s_h;
	void	*we_tex;
	char	*we_texadr;
	int		w_w;
	int		w_h;
	void	*ea_tex;
	char	*ea_texadr;
	int		e_w;
	int		e_h;
	char	*no_textr;
	char	*so_textr;
	char	*we_textr;
	char	*ea_textr;
	int		floor_c;
	int		ceilling_c;
}		t_game;

// ----------------- Parse -------------------

void	parse(t_game *game, char *path);
int		check_line(t_game *game, char *line);
char	*check_path(char *path);
int		is_empty(char *str);
void	valid_space(char **map, int i, int j);

// ----------------- Shared -------------------

void	*alloc(size_t size);
void	ft_lstclear(void);
int		ft_strlen(const char *s);
char	*ft_strdup(char *s);
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
void	ft_castray1(t_game *game, double x2, double y2);
double	degtorad(double a);
double	dist(float ax, float ay, float bx, float by);
int		ft_hook(t_game *game);
void	ft_drawceilling(t_game *game, float lineo);
void	ft_drawfloor(t_game *game, double lineh, float lineo);
void	ft_moveup(t_game *game);
void	ft_movedown(t_game *game);
void	ft_rotateright(t_game *game);
void	ft_rotateleft(t_game *game);
void	ft_moveright(t_game *game);
void	ft_moveleft(t_game *game);
double	fixang(double a);
void	draw_rays(t_game *game);
int		key_hook1(int keycode, t_game *game);
int		key_hook2(int keycode, t_game *game);
void	ft_drawline3(t_game *game, float y1, double lineh, float x);
void	ft_drawline4(t_game *game, float y1, double lineh, float x);
int		red_cross(void);

t_allocs	**g_allocs;

#endif
