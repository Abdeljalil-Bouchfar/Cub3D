/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:21:40 by ressalhi          #+#    #+#             */
/*   Updated: 2022/11/08 18:37:09 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_open_file(char *map_file, int perm)
{
	int	fd;

	fd = open(map_file, perm);
	if (fd <= 0)
		ft_error("Map file Wrong!!\n");
	return (fd);
}

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

void	read_file(t_game *game, int fd)
{
	int		count;
	char	*line;
	char	*str;

	str = ft_strdup("");
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (*line == '\n' && count == 6)
			continue ;
		if (count >= 6)
		{
			if (*line == '\n')
				ft_error("Error: Invalid Map\nEmpty line\n");
			str = ft_strjoin(str, line);
			count++;
		}
		else if (*line != '\n')
			count += check_line(game, line);
	}
	game->map = ft_split(str, '\n');
}

int	validate_line(char *line, char *pre, char *next)
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
		if ((line[j] != '1' && line[j] != ' ' && line[j] != '\t'
				&& (j == 0 || line[j + 1] == '\0' || next == NULL || pre == NULL
					|| j >= ft_strlen(next) || j >= ft_strlen(pre)
					|| (j < ft_strlen(next) && (next[j] == ' '
							|| next[j] == '\t')) || (j < ft_strlen(pre)
						&& (pre[j] == ' ' || pre[j] == '\t'))))
			|| (line[j] != '1' && line[j] != '0' && line[j] != 'N'
				&& line[j] != 'S' && line[j] != 'E' && line[j] != 'W'
				&& line[j] != '2' && line[j] != '3' && line[j] != '4'
				&& line[j] != ' ' && line[j] != '\t'))
		{
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
	fd = ft_open_file(path, O_RDONLY);
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
		c += validate_line(game->map[i], pre, next);
	}
	if (c != 1 || i < 3)
		ft_error("Error: Invalid Map\nMissing value\n");
}
