/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:40:27 by abouchfa          #+#    #+#             */
/*   Updated: 2022/11/09 18:04:00 by abouchfa         ###   ########.fr       */
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
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
	}
	return (1);
}
