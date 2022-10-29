/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:40:27 by abouchfa          #+#    #+#             */
/*   Updated: 2022/10/29 16:58:14 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	get_color(char *line)
{
	char	*tmp;
	int		rgb[3];
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	while (line[i])
	{
		while (line[i] && !ft_isdigit(line[i]))
		{
			if (line[i] == ',')
				n++;
			i++;
		}
		j = i;
		while (ft_isdigit(line[j]))
			j++;
		if (n < 3 && i != j)
		{
			tmp = malloc(sizeof(char) * (j - i + 1));
			ft_strlcpy(tmp, line + i, j - i + 1);
			rgb[n] = ft_atoi(tmp);
			if (rgb[n] < 0 || rgb[n] > 255)
				ft_error("Error: Invalid Color\n");
		}
		i = j;
		if (n > 2)
			ft_error("Error: Invalid Color\n");
	}
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	set_data(t_game *game, char *line, int code)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	j = i;
	while (line[j] && line[j] != '\n' && (line[j] != ' ' || code == 4 || code == 5))
		j++;
	res = malloc(sizeof(char) * (j - i + 1));
	ft_strlcpy(res, line + i, j - i + 1);
	if ((code == 0 && game->no_textr) || (code == 1 && game->so_textr)
		|| (code == 2 && game->we_textr) || (code == 3 && game->ea_textr)
		|| (code == 4 && game->floor_c != -1) || (code == 5 && game->ceilling_c != -1))
		{
			ft_error("Error: Duplicate values\n");
		}
	if (code == 0 && j - i > 0)
		game->no_textr = res;
	else if (code == 1 && j - i > 0)
		game->so_textr = res;
	else if (code == 2 && j - i > 0)
		game->we_textr = res;
	else if (code == 3 && j - i > 0)
		game->ea_textr = res;
	else if (code == 4 && j - i > 0)
		game->floor_c = get_color(res);
	else if (code == 5 && j - i > 0)
		game->ceilling_c = get_color(res);
	return (1);
}

int	extract_data(t_game *game, char *line)
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
			if (j - i == 2 && !ft_strncmp(line + i, "NO", j - i))
				return set_data(game, line + j, 0);
			else if(j - i == 2 && !ft_strncmp(line + i, "SO", j - i))
				return set_data(game, line + j, 1);
			else if(j - i == 2 && !ft_strncmp(line + i, "WE", j - i))
				return set_data(game, line + j, 2);
			else if(j - i == 2 && !ft_strncmp(line + i, "EA", j - i))
				return set_data(game, line + j, 3);
			else if(line[i] == 'F' && line[i + 1] == ' ')
				return set_data(game, line + j, 4);
			else if(line[i] == 'C' && line[i + 1] == ' ')
				return set_data(game, line + j, 5);
		}
	}
	return (0);
}