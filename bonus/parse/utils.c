/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:40:27 by abouchfa          #+#    #+#             */
/*   Updated: 2022/10/27 15:28:28 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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
			if (ft_strncmp(line + i, "NO", j - i)
				|| ft_strncmp(line + i, "SO", j - i)
				|| ft_strncmp(line + i, "WE", j - i)
				|| ft_strncmp(line + i, "EA", j - i)
				|| ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' '))
			{
				set_data(game, line + j, stage);
				return (1);
			}
		}
	}
	return (0);
}
