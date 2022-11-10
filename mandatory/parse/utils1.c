/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:40:27 by abouchfa          #+#    #+#             */
/*   Updated: 2022/11/09 18:06:53 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_nbr(char *line, int *c)
{
	char	*tmp;
	int		j;

	j = 0;
	while (line[j] && ft_isdigit(line[j]))
		j++;
	if (j > 0)
	{
		tmp = alloc(sizeof(char) * (j + 1));
		ft_strlcpy(tmp, line, j + 1);
		*c = ft_atoi(tmp);
		if (*c < 0 || *c > 255 || j > 3)
			ft_error("Error: Invalid Color 1\n");
	}
	return (j);
}

int	get_color(char *line)
{
	int		rgb[3];
	int		i;
	int		n;
	int		q;

	i = 0;
	q = 0;
	n = -1;
	while (i < ft_strlen(line))
	{
		i += set_nbr(line + i, &rgb[++n]);
		while (i < ft_strlen(line) && !ft_isdigit(line[i]))
		{
			if (line[i] == ',')
				q++;
			else if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
				ft_error("Error: Invalid Color 2\n");
			i++;
		}
	}
	if (n != 2 || q != 2)
		ft_error("Error: Invalid Color 3\n");
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	route_values(t_game *game, char c, char *res)
{
	if (c == 'N')
		game->no_textr = check_path(res);
	else if (c == 'S')
		game->so_textr = check_path(res);
	else if (c == 'W')
		game->we_textr = check_path(res);
	else if (c == 'E')
		game->ea_textr = check_path(res);
	else if (c == 'F')
		game->floor_c = get_color(res);
	else if (c == 'C')
		game->ceilling_c = get_color(res);
}

int	set_values(t_game *game, char *line, char c)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	j = i;
	while (line[j] && line[j] != '\n')
	{
		if ((line[j] == ' ' || line[j] == '\t') && c != 'F' && c != 'C')
			break ;
		j++;
	}
	res = alloc(sizeof(char) * (j - i + 1));
	ft_strlcpy(res, line + i, j - i + 1);
	if ((c == 'N' && game->no_textr) || (c == 'S' && game->so_textr)
		|| (c == 'W' && game->we_textr) || (c == 'E' && game->ea_textr)
		|| (c == 'F' && game->floor_c != -1)
		|| (c == 'C' && game->ceilling_c != -1))
		ft_error("Error: Duplicate values\n");
	if (j - i > 0)
		route_values(game, c, res);
	return (1);
}

int	check_line(t_game *game, char *line)
{
	int	i;
	int	j;

	i = -1;
	while (line[++i])
	{
		if ((i == 0 || line[i - 1] == ' ' || line[i - 1] == '\t')
			&& line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			j = i + 1;
			while (line[j] && line[j] != ' ' && line[j] != '\t')
				j++;
			if (j - i == 2 && !ft_strncmp(line + i, "NO", j - i))
				return (set_values(game, line + j, line[i]));
			else if (j - i == 2 && !ft_strncmp(line + i, "SO", j - i))
				return (set_values(game, line + j, line[i]));
			else if (j - i == 2 && !ft_strncmp(line + i, "WE", j - i))
				return (set_values(game, line + j, line[i]));
			else if (j - i == 2 && !ft_strncmp(line + i, "EA", j - i))
				return (set_values(game, line + j, line[i]));
			else if ((line[i] == 'F' || line[i] == 'C')
				&& (line[i + 1] == ' ' || line[i + 1] == '\t'))
				return (set_values(game, line + j, line[i]));
		}
	}
	return (0);
}