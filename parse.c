/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:21:40 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/21 18:29:14 by abouchfa         ###   ########.fr       */
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

void	set_elements(t_game *game, char *line, int *stage)
{
	int	i;
	int	j;
	int	f;

	i = -1;
	f = -1;
	(void) game;
	(void) stage;
	while(line[++i])
	{
		j = i;
		if (line[i] != ' ')
			while(line[j] && line[j] != ' ')
				j++;
		
	}
}

void	ft_read_map(t_game *game, char *map_file)
{
	int		fd;
	//int		stage;
	char	*line;
	char	*str;

	fd = ft_open_file(map_file);
	str = ft_strdup("");
	//stage = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		//if (stage == 6)
		str = ft_strjoin(str, line);
		// else
		// 	set_elements(game, line, &stage);
		free(line);
	}
	free(line);
	game->map = ft_split(str, '\n');
	free(str);
}

void	parse(t_game *game, char *path)
{
	game->floor_c = -1;
	game->ceilling_c = -1;
	validate_path(path, ".cub");
	ft_read_map(game, path);
}

// int main(int ac, char **av)
// {
// 	t_game	*game;

// 	if (ac != 2)
// 		ft_error("Error\nWrong Number Of Args\n");
// 	game = malloc(sizeof(t_game));
// 	parse(game, av[1]);
// 	char **tmp = game->map;
// 	int i = -1;
// 	// printf("NO: %s\n", game->no_textr);
// 	// printf("SO: %s\n", game->so_textr);
// 	// printf("WE: %s\n", game->we_textr);
// 	// printf("EA: %s\n", game->ea_textr);
// 	// printf("FC: %i\n", game->floor_c);
// 	// printf("CE: %i\n", game->ceilling_c);
// 	while (tmp[++i])
// 		printf("%s\n", tmp[i]);
// }
