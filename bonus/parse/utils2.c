/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:40:27 by abouchfa          #+#    #+#             */
/*   Updated: 2022/11/10 20:41:01 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		ft_error("XPM file Wrong!!\n");
	close(fd);
	return (path);
}

int	is_empty(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (0);
	}
	return (1);
}

void	valid_space(char **map, int i, int j)
{
	if (j == -1 || i == -1 || !map[i]
		|| j >= ft_strlen(map[i]) || map[i][j] == ' ')
		ft_error("Error: Invalid Map\n");
	if (map[i][j] == '1')
		return ;
	map[i][j] = '1';
	valid_space(map, i + 1, j);
	valid_space(map, i, j + 1);
	valid_space(map, i - 1, j);
	valid_space(map, i, j - 1);
}
