/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:21:40 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/26 16:14:52 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	read_file(t_game *game, int fd)
{
	int		stage;
	char	*line;
	char	*str;

	str = ft_strdup("");
	stage = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (stage <= 6 && *line == '\n')
			continue ;
		if (stage >= 6)
		{
			if (*line == '\n')
				ft_error("Error: Invalid Map 3\n");
			str = ft_strjoin(str, line);
			stage++;
		}
		else
			stage += set_elements(game, line, stage);
	}
	game->map = ft_split(str, '\n');
}

int	validate_line(char *line, char *pre, char *next, int i)
{
	int	c;
	int	j;

	c = 0;
	j = -1;
	while (line[++j])
	{
		if (line[j] == 'N' || line[j] == 'S'
			|| line[j] == 'E' || line[j] == 'W')
			c++;
		if ((line[j] != '1' && line[j] != ' '
				&& (j == 0 || line[j + 1] == '\0'
					|| next == NULL || pre == NULL
					|| j >= ft_strlen(next) || j >= ft_strlen(pre)
					|| (j < ft_strlen(next) && next[j] == ' ')
					|| (j < ft_strlen(pre) && pre[j] == ' ')))
			|| (line[j] != '1' && line[j] != '0' && line[j] != 'N'
				&& line[j] != 'S' && line[j] != 'E' && line[j] != 'W'
				&& line[j] != ' ' && line[j] != '	'))
				{
					printf("%i %i\n", i, j);
					ft_error("Error: Invalid Map\n");
				}
	}
	return (c);
}

void	parse(t_game *game, char *path)
{
	int		i;
	int		c;
	int		fd;
	char	*next;
	char	*pre;

	validate_path(path, ".cub");
	fd = ft_open_file(path);
	read_file(game, fd);
	i = -1;
	c = 0;
	while (game->map && game->map[++i])
	{
		if (i == 0)
			pre = NULL;
		else
			pre = game->map[i - 1];
		next = game->map[i + 1];
		c += validate_line(game->map[i], pre, next, i);
	}
	if (c != 1 || i < 3)
		ft_error("Error: Invalid Map\n");
}

// int main(int ac, char **av)
// {
// 	t_game	*game;
// 	int		i;

// 	if (ac != 2)
// 		ft_error("Error\nWrong Number Of Args\n");
// 	game = malloc(sizeof(t_game));
// 	parse(game, av[1]);
// 	printf("NO: %s\n", game->no_textr);
// 	printf("SO: %s\n", game->so_textr);
// 	printf("WE: %s\n", game->we_textr);
// 	printf("EA: %s\n", game->ea_textr);
// 	printf("FC: %i\n", game->floor_c);
// 	printf("CE: %i\n", game->ceilling_c);
// 	i = -1;
// 	while (game->map[++i])
// 		printf("%s\n", game->map[i]);
// }