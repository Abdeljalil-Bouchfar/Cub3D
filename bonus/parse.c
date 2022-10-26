/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:21:40 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/26 12:20:25 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_path(char *str, char *cub)
{
	int	i;
	int	j;

	i = ft_strlen(str) - ft_strlen(cub);
	if (i <= 0 || str[i] != '.')
		ft_error("Wrong File!!\n");
	j = 0;
	while (str[i + j] != '\0' && cub[j] != '\0')
	{
		if (str[i + j] == cub[j])
			j++;
		else
			break ;
	}
	if (!(str[i + j] == '\0' && cub[j] == '\0'))
		ft_error("That's Wrong!!, It Should be (*.cub)\n");
}

int	ft_open_file(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd <= 0)
		ft_error("Map file Wrong!!\n");
	return (fd);
}

int	get_color(char **str)
{
	uint8_t	rgb[3];
	int		i;
	int		j;

	i = -1;
	while (str && str[++i])
	{
		j = -1;
		while (str[i][++j])
			if (!ft_isdigit(str[i][j]))
				ft_error("Error: Invalid Color\n");
		if (i < 3)
			rgb[i] = ft_atoi(str[i]);
	}
	if (i != 3)
		ft_error("Error: Invalid Color\n");
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	set_data(t_game *game, char *line, int stage)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while ((line[i] == ' ' || line[i] == '	') && line[i])
		i++;
	j = i;
	while (line[j] != '\n' && line[j] != ' ' && line[j])
		j++;
	res = malloc(sizeof(char) * (j - i + 1));
	ft_strlcpy(res, line + i, j - i + 1);
	if (stage == 0 && j - i > 0)
		game->no_textr = res;
	else if (stage == 1 && j - i > 0)
		game->so_textr = res;
	else if (stage == 2 && j - i > 0)
		game->we_textr = res;
	else if (stage == 3 && j - i > 0)
		game->ea_textr = res;
	else if (stage == 4 && j - i > 0)
		game->floor_c = get_color(ft_split(res, ','));
	else if (stage == 5 && j - i > 0)
		game->ceilling_c = get_color(ft_split(res, ','));
}

int	set_elements(t_game *game, char *line, int stage)
{
	int	i;
	int	j;

	i = -1;
	while (line[++i])
	{
		j = i;
		if (line[i] != ' ' && line[i] != '\n')
		{
			while (line[j] && line[j] != ' ')
				j++;
			if (ft_strncmp(line + i, "NO", j - i) || ft_strncmp(line + i, "SO", j - i) ||
				ft_strncmp(line + i, "WE", j - i) || ft_strncmp(line + i, "EA", j - i) ||
				((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' '))
			{
				set_data(game, line + j, stage);
				return (1);
			}
		}
	}
	return (0);
}

void	read_file(t_game *game, char *map_file)
{
	int		fd;
	int		stage;
	char	*line;
	char	*str;

	fd = ft_open_file(map_file);
	str = ft_strdup("");
	stage = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (stage == 6 && *line == '\n')
			continue ;
		if (stage >= 6)
		{
			if (*line == '\n')
				ft_error("Error: Invalid Map\n");
			str = ft_strjoin(str, line);
			stage++;
		}
		else
			stage += set_elements(game, line, stage);
		free(line);
	}
	free(line);
	game->map = ft_split(str, '\n');
	if (stage < 8)
		ft_error("Error: Invalid Map\n");
	free(str);
}

void	validate_map(char **map)
{
	char	*tmp;
	size_t	i;
	size_t	c;
	size_t	j;

	i = -1;
	c = 0;
	while (map[++i])
	{
		j = -1;
		tmp = map[i];
		while (tmp[++j])
		{
			if (tmp[j] == 'N' || tmp[j] == 'S' || tmp[j] == 'E' || tmp[j] == 'W')
				c++;
			if (c > 1 || ((j == 0 || tmp[j + 1] == '\0' || tmp[j + 1] == ' ' ||
				i == 0 || map[i + 1] == NULL ||
				(map[i + 1] && j < ft_strlen(map[i + 1]) && map[i + 1][j] == ' ') ||
				(i > 0 && j < ft_strlen(map[i - 1]) && map[i - 1][j] == ' ')) &&
				tmp[j] != '1' && tmp[j] != ' ') ||
				(tmp[j] != '1' && tmp[j] != '0' && tmp[j] != 'N' &&
				tmp[j] != 'S' && tmp[j] != 'E' && tmp[j] != 'W' &&
				tmp[j] != ' ' && tmp[j] != '	'))
				{
					//printf("%i %i\n", i, j);
					ft_error("Error: Invalid Map\n");
				}
		}
	}
	if (c != 1)
		ft_error("Error: Invalid Map\n");
}

void	parse(t_game *game, char *path)
{
	game->floor_c = -1;
	game->ceilling_c = -1;
	validate_path(path, ".cub");
	read_file(game, path);
	validate_map(game->map);
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
