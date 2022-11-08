/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:40:27 by abouchfa          #+#    #+#             */
/*   Updated: 2022/11/08 18:21:14 by abouchfa         ###   ########.fr       */
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
			{
				ft_error("Error: Invalid Color 2\n");
			}
			i++;
		}
		if (n > 2 || q > 2)
			ft_error("Error: Invalid Color 3\n");
	}
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	route_values(t_game *game, int code, char *res)
{
	if (code == 0)
		game->no_textr = res;
	else if (code == 1)
		game->so_textr = res;
	else if (code == 2)
		game->we_textr = res;
	else if (code == 3)
		game->ea_textr = res;
	else if (code == 4)
		game->floor_c = get_color(res);
	else if (code == 5)
		game->ceilling_c = get_color(res);
}

int	set_values(t_game *game, char *line, int code)
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
		if ((line[j] == ' ' || line[i] == '\t') && code < 4)
			break ;
		j++;
	}
	res = alloc(sizeof(char) * (j - i + 1));
	ft_strlcpy(res, line + i, j - i + 1);
	if ((code == 0 && game->no_textr) || (code == 1 && game->so_textr)
		|| (code == 2 && game->we_textr) || (code == 3 && game->ea_textr)
		|| (code == 4 && game->floor_c != -1)
		|| (code == 5 && game->ceilling_c != -1))
		ft_error("Error: Duplicate values\n");
	if (j - i > 0)
		route_values(game, code, res);
	return (1);
}

int	check_line(t_game *game, char *line)
{
	int	i;
	int	j;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '\n')
		{
			j = i;
			while (line[j] && line[j] != ' ')
				j++;
			if (j - i == 2 && !ft_strncmp(line + i, "NO", j - i))
				return (set_values(game, line + j, 0));
			else if (j - i == 2 && !ft_strncmp(line + i, "SO", j - i))
				return (set_values(game, line + j, 1));
			else if (j - i == 2 && !ft_strncmp(line + i, "WE", j - i))
				return (set_values(game, line + j, 2));
			else if (j - i == 2 && !ft_strncmp(line + i, "EA", j - i))
				return (set_values(game, line + j, 3));
			else if (line[i] == 'F' && line[i + 1] == ' ')
				return (set_values(game, line + j, 4));
			else if (line[i] == 'C' && line[i + 1] == ' ')
				return (set_values(game, line + j, 5));
		}
	}
	return (0);
}
