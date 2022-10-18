/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:21:40 by ressalhi          #+#    #+#             */
/*   Updated: 2022/10/18 16:46:38 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map(char *str, char *cub)
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

void	ft_read_map(t_game *game, char *map_file)
{
	int		fd;
	char	*line;
	char	*str;

	fd = ft_open_file(map_file);
	str = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str = ft_strjoin(str, line);
		free(line);
	}
	free(line);
	game->map = ft_split(str, '\n');
	free(str);
}

void	ft_map(t_game *game, char *str)
{
	ft_check_map(str, ".cub");
	ft_read_map(game, str);
}
