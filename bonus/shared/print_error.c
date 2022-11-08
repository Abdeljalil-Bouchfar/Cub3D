/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:46:50 by abouchfa          #+#    #+#             */
/*   Updated: 2022/11/08 15:52:52 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_rotateleft(t_game *g)
{
	g->pa -= 3;
	if (g->pa < 0)
		g->pa += 360;
	g->pdx = cos(degtorad(g->pa)) * P_SPEED;
	g->pdy = sin(degtorad(g->pa)) * P_SPEED;
}

int	red_cross(void)
{
	ft_error("EXIT\n");
	return (0);
}

void	ft_error(char *str)
{
	printf("%s", str);
	exit (1);
}
